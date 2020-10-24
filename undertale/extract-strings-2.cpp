#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include <fstream>
#include <unordered_map>
#include <vector>

#include "undertale.h"

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

  std::ifstream   ifs{argv[1], std::ifstream::binary};
  kaitai::kstream ks(&ifs);
  undertale_t     data = undertale_t(&ks);

  for (auto const& str : *data.form()->strg()->data()->strings())
    std::printf("%d %s\n", str->size(), str->string().c_str());

  return 0;
}
