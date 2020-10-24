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
  if (argc < 3 || std::find_if(argv, argv + argc, [](auto& a) {
                    return std::strcmp(a, "--help") == 0 ||
                           std::strcmp(a, "-h") == 0;
                  }) != argv + argc)
    return std::printf("Usage: undertale-game2po <input> <pofile>\n\n"
                       "  <input>   Untranslated game.dat or game.unx\n"
                       "  <pofile>  File containing untranslated strings\n");

  auto offsets = std::vector<uint32_t>{};
  auto strings = std::vector<std::string>{};

  auto in = std::ifstream{argv[1], std::ios::binary};
  while (in.good()) {
    auto chunk = chunk_header{};

    in.read(reinterpret_cast<char*>(&chunk), sizeof(chunk));
    if (!in.good())
      break;

    switch (chunk.magic) {
    case "FORM"_4cc:
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
    case "AUDO"_4cc:
      in.seekg(chunk.size, std::ios::cur);
      break;
    case "STRG"_4cc: {
      auto next = chunk.size + in.tellg();
      auto strg = strg_header{};
      in.read(reinterpret_cast<char*>(&strg), sizeof(strg));

      offsets.resize(strg.count);
      strings.resize(strg.count);
      in.read(reinterpret_cast<char*>(&offsets[0]),
              strg.count * sizeof(offsets[0]));

      for (size_t i = 0; i < strg.count; ++i) {
        in.seekg(offsets[i], std::ios::beg);

        uint32_t length = 0;
        in.read(reinterpret_cast<char*>(&length), sizeof(length));

        std::getline(in, strings[i], '\0');
        assert(length == utf8size(strings[i].c_str()));
      }

      in.seekg(next, std::ios::beg);
      break;
    }
    }
  }

  auto out = std::ofstream{argv[2]};
  out << "msgid \"\"\n";
  out << "msgstr \"\"\n";
  out << "\"Project-Id-Version: Undertale\\n\"\n";
  out << "\"Language: en_US\\n\"\n";
  out << "\"MIME-Version: 1.0\\n\"\n";
  out << "\"Content-Type: text/plain; charset=UTF-8\\n\"\n";
  out << "\"Content-Transfer-Encoding: 8bit\\n\"\n";

  for (auto& str : strings) {
    size_t line = (&str - &strings[0]);
    if (line >= 1950 && line <= 2380)
      continue;
    if (line >= 19340)
      break;

    boost::replace_all(str, "\\", "\\\\");
    boost::replace_all(str, "\"", "\\\"");
    boost::replace_all(str, "\n", "\\n");
    boost::replace_all(str, "\r", "\\r");
    out << "msgctxt " << line << "\nmsgid \"" << str << "\"\nmsgstr \"" << str
        << "\"\n";
  }

  return 0;
}
