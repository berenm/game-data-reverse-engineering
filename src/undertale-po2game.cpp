#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/replace.hpp>

constexpr static uint32_t operator""_4cc(char const* value, size_t size) {
  assert(size == 4);
  return (value[0] << 0) | (value[1] << 8) | (value[2] << 16) |
         (value[3] << 24);
}

static uint32_t utf8size(char const* string) {
  uint32_t len = 0;
  while (*string)
    len += (*string++ & 0xc0) != 0x80;
  return len;
}

struct chunk_header {
  union {
    uint32_t magic;
    char     magic_str[4];
  };
  uint32_t size;
};

struct strg_header {
  uint32_t count;
};

int main(int argc, char const* argv[]) {
  if (argc < 4 || std::find_if(argv, argv + argc, [](auto& a) {
                    return std::strcmp(a, "--help") == 0 ||
                           std::strcmp(a, "-h") == 0;
                  }) != argv + argc)
    return std::printf("Usage: undertale-po2game <pofile> <input> <output>\n\n"
                       "  <pofile>  File containing translated strings\n"
                       "  <input>   Untranslated game.dat or game.unx\n"
                       "  <output>  Output translated game data file\n");

  auto ioffsets = std::vector<uint32_t>{};
  auto ooffsets = std::vector<uint32_t>{};
  auto strings  = std::vector<std::string>{};

  auto in     = std::ifstream{argv[2], std::ios::binary};
  auto out    = std::ofstream{argv[3], std::ios::binary};
  auto buffer = std::vector<char>{};

  auto end_file = 0;
  while (in.good()) {
    auto chunk = chunk_header{};

    in.read(reinterpret_cast<char*>(&chunk), sizeof(chunk));
    if (!in.good())
      break;

    switch (chunk.magic) {
    case "FORM"_4cc:
      out.write(reinterpret_cast<char*>(&chunk), sizeof(chunk));
      end_file = chunk.size + 8;
      break;
    case "GEN8"_4cc:
    case "OPTN"_4cc:
    case "EXTN"_4cc:
    case "SOND"_4cc:
    case "AGRP"_4cc:
    case "SPRT"_4cc:
    case "BGND"_4cc:
    case "PATH"_4cc:
    case "SCPT"_4cc:
    case "SHDR"_4cc:
    case "FONT"_4cc:
    case "TMLN"_4cc:
    case "OBJT"_4cc:
    case "ROOM"_4cc:
    case "DAFL"_4cc:
    case "TPAG"_4cc:
    case "CODE"_4cc:
    case "VARI"_4cc:
    case "FUNC"_4cc:
    case "TXTR"_4cc:
    case "AUDO"_4cc: {
      out.write(reinterpret_cast<char*>(&chunk), sizeof(chunk));
      buffer.resize(chunk.size);
      in.read(&buffer[0], buffer.size());
      out.write(&buffer[0], buffer.size());
      break;
    }

    case "STRG"_4cc: {
      auto next = chunk.size + in.tellg();
      auto strg = strg_header{};
      in.read(reinterpret_cast<char*>(&strg), sizeof(strg));

      ioffsets.resize(strg.count);
      strings.resize(strg.count);
      in.read(reinterpret_cast<char*>(&ioffsets[0]),
              strg.count * sizeof(ioffsets[0]));

      auto beg_strings = in.tellg();
      for (size_t i = 0; i < strg.count; ++i) {
        in.seekg(ioffsets[i], std::ios::beg);

        uint32_t length = 0;
        in.read(reinterpret_cast<char*>(&length), sizeof(length));

        std::getline(in, strings[i], '\0');
        assert(length == strings[i].size());
      }

      out.write(reinterpret_cast<char*>(&chunk), sizeof(chunk));
      out.write(reinterpret_cast<char*>(&strg), sizeof(strg));
      out.write(reinterpret_cast<char*>(&ioffsets[0]),
                strg.count * sizeof(ioffsets[0]));

      buffer.resize(next - beg_strings);
      in.seekg(beg_strings, std::ios::beg);
      in.read(&buffer[0], buffer.size());
      out.write(&buffer[0], buffer.size());
      break;
    }
    }
  }

  auto ins = std::ifstream{argv[1], std::ios::binary};
  while (ins.good()) {
    auto _ = std::string{};
    ins >> _;
    if (!ins.good())
      break;

    if (_ != "msgctxt" || ins.get() != ' ') {
      std::getline(ins, _, '\n');
    } else {
      auto line = -1;
      ins >> line;

      ins >> _;
      assert(_ == "msgid");
      ins.get();
      ins.get();

      auto msgid = std::string{};
      std::getline(ins, msgid, '\n');
      msgid.pop_back();
      boost::replace_all(msgid, "\\\\", "\\");
      boost::replace_all(msgid, "\\\"", "\"");
      boost::replace_all(msgid, "\\n", "\n");
      boost::replace_all(msgid, "\\r", "\r");

      ins >> _;
      assert(_ == "msgstr");
      ins.get();
      ins.get();

      auto msgstr = std::string{};
      std::getline(ins, msgstr, '\n');
      msgstr.pop_back();
      boost::replace_all(msgstr, "\\\\", "\\");
      boost::replace_all(msgstr, "\\\"", "\"");
      boost::replace_all(msgid, "\\n", "\n");
      boost::replace_all(msgid, "\\r", "\r");

      if (strings[line] == msgid)
        strings[line] = msgstr;
      else
        std::printf("err: %d: %s doestn't match msgid %s\n", line,
                    strings[line].c_str(), msgid.c_str());
    }
  }

  auto chunk  = chunk_header{};
  auto strg   = strg_header{};
  chunk.magic = "STRG"_4cc;
  chunk.size  = 4 + 4 * strings.size();
  for (size_t i = 0; i < strings.size(); ++i) {
    ooffsets.push_back(end_file + 8 + chunk.size);
    chunk.size += sizeof(uint32_t) + strings[i].size() + 1;
    strg.count++;
  }

  out.write(reinterpret_cast<char*>(&chunk), sizeof(chunk));
  out.write(reinterpret_cast<char*>(&strg), sizeof(strg));
  out.write(reinterpret_cast<char*>(&ooffsets[0]),
            strg.count * sizeof(ooffsets[0]));

  for (size_t i = 0; i < strings.size(); ++i) {
    uint32_t length = utf8size(strings[i].c_str());
    out.write(reinterpret_cast<char*>(&length), sizeof(length));
    out.write(strings[i].c_str(), strings[i].size() + 1);
  }

  uint32_t size = static_cast<uint32_t>(out.tellp()) - 8;
  out.seekp(4, std::ios::beg);
  out.write(reinterpret_cast<char*>(&size), 4);

  return 0;
}
