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
  if (argc < 2) return -1;

  auto offsets = std::vector< uint32_t >{};
  auto strings = std::vector< std::pair< uint32_t, std::string > >{};

  auto in = std::ifstream{argv[1], std::ios::binary};
  while (in.good()) {
    auto chunk = chunk_header{};

    in.read(reinterpret_cast< char* >(&chunk), sizeof(chunk));
    if (!in.good()) break;

    switch (chunk.magic) {
      case "FORM"_4cc: break;
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
      case "AUDO"_4cc: in.seekg(chunk.size, std::ios::cur); break;
      case "STRG"_4cc: {
        auto next = chunk.size + in.tellg();
        auto strg = strg_header{};
        in.read(reinterpret_cast< char* >(&strg), sizeof(strg));

        offsets.resize(strg.count);
        strings.resize(strg.count);
        in.read(reinterpret_cast< char* >(&offsets[0]),
                strg.count * sizeof(offsets[0]));

        for (size_t i = 0; i < strg.count; ++i) {
          in.seekg(offsets[i], std::ios::beg);

          uint32_t length = 0;
          in.read(reinterpret_cast< char* >(&length), sizeof(length));

          strings[i].first = length;
          std::getline(in, strings[i].second, '\0');
        }

        in.seekg(next, std::ios::beg);
        break;
      }
    }
  }

  for (auto& pair : strings)
    std::printf("%d %s\n", pair.first, pair.second.c_str());

  return 0;
}
