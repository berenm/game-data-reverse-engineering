#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <fstream>
#include <unordered_map>
#include <vector>

constexpr static uint32_t operator""_4cc(char const* value, size_t size) {
  assert(size == 4);
  return (value[0] << 0) | (value[1] << 8) | (value[2] << 16)
         | (value[3] << 24);
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
  if (argc < 4) return -1;

  auto ioffsets = std::vector< uint32_t >{};
  auto ooffsets = std::vector< uint32_t >{};
  auto istrings = std::vector< std::pair< uint32_t, std::string > >{};
  auto ostrings = std::vector< std::pair< uint32_t, std::string > >{};

  auto ins = std::ifstream{argv[2], std::ios::binary};
  while (ins.good()) {
    auto length = 0;
    ins >> length;
    if (!ins.good()) break;

    ostrings.emplace_back();
    ostrings.back().first = length;
    assert(ins.get() == ' ');
    std::getline(ins, ostrings.back().second, '\n');
  }

  auto in     = std::ifstream{argv[1], std::ios::binary};
  auto out    = std::ofstream{argv[3], std::ios::binary};
  auto buffer = std::vector< char >{};

  auto end_file = 0;
  while (in.good()) {
    auto chunk = chunk_header{};

    in.read(reinterpret_cast< char* >(&chunk), sizeof(chunk));
    if (!in.good()) break;

    switch (chunk.magic) {
      case "FORM"_4cc:
        out.write(reinterpret_cast< char* >(&chunk), sizeof(chunk));
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
        out.write(reinterpret_cast< char* >(&chunk), sizeof(chunk));
        buffer.resize(chunk.size);
        in.read(&buffer[0], buffer.size());
        out.write(&buffer[0], buffer.size());
        break;
      }

      case "STRG"_4cc: {
        auto next = chunk.size + in.tellg();
        auto strg = strg_header{};
        in.read(reinterpret_cast< char* >(&strg), sizeof(strg));

        ioffsets.resize(strg.count);
        istrings.resize(strg.count);
        in.read(reinterpret_cast< char* >(&ioffsets[0]),
                strg.count * sizeof(ioffsets[0]));

        auto beg_strings = in.tellg();
        for (size_t i = 0; i < strg.count; ++i) {
          in.seekg(ioffsets[i], std::ios::beg);

          uint32_t length = 0;
          in.read(reinterpret_cast< char* >(&length), sizeof(length));

          istrings[i].first = length;
          std::getline(in, istrings[i].second, '\0');
        }

        out.write(reinterpret_cast< char* >(&chunk), sizeof(chunk));
        out.write(reinterpret_cast< char* >(&strg), sizeof(strg));
        out.write(reinterpret_cast< char* >(&ioffsets[0]),
                  strg.count * sizeof(ioffsets[0]));

        buffer.resize(next - beg_strings);
        in.seekg(beg_strings, std::ios::beg);
        in.read(&buffer[0], buffer.size());
        out.write(&buffer[0], buffer.size());
        break;
      }
    }
  }

  auto chunk  = chunk_header{};
  auto strg   = strg_header{};
  chunk.magic = "STRG"_4cc;
  chunk.size  = 4 + 4 * ostrings.size();
  for (size_t i = 0; i < ostrings.size(); ++i) {
    ooffsets.push_back(end_file + 8 + chunk.size);
    chunk.size += sizeof(ostrings[i].first) + ostrings[i].second.size() + 1;
    strg.count++;
  }

  out.write(reinterpret_cast< char* >(&chunk), sizeof(chunk));
  out.write(reinterpret_cast< char* >(&strg), sizeof(strg));
  out.write(reinterpret_cast< char* >(&ooffsets[0]),
            strg.count * sizeof(ooffsets[0]));

  for (size_t i = 0; i < ostrings.size(); ++i) {
    out.write(reinterpret_cast< char* >(&ostrings[i].first),
              sizeof(ostrings[i].first));
    out.write(ostrings[i].second.c_str(), ostrings[i].second.size() + 1);
  }

  uint32_t size = static_cast< uint32_t >(out.tellp()) - 8;
  out.seekp(4, std::ios::beg);
  out.write(reinterpret_cast< char* >(&size), 4);

  return 0;
}
