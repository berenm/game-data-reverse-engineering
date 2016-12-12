#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <string>
#include <vector>

#include <sys/stat.h>
#include <sys/types.h>

struct decompress_args {
  uint8_t* cbuffer;
  uint8_t* dbuffer;
  size_t   dsize;
};

bool   is_compressed = true;
size_t dblock_size   = 0x7d000;

int decompress_block(size_t   csize,
                     uint8_t* cbuffer,
                     uint8_t* dbuffer,
                     size_t*  bsize);

uint8_t* decompress(decompress_args& args, size_t bcount) {
  std::printf("decompress: bcount: %d\n", bcount);

  if (is_compressed) {
    args.dsize     = 0;
    uint8_t* dbuf  = args.dbuffer;
    uint8_t* cbuf  = args.cbuffer;
    size_t   block = 0;

    while (block < bcount) {
      size_t dsize
        = (cbuf[3] << 24) | (cbuf[2] << 16) | (cbuf[1] << 8) | (cbuf[0] << 0);
      cbuf += 4;
      if (dsize == 0) break;

      size_t csize
        = (cbuf[3] << 24) | (cbuf[2] << 16) | (cbuf[1] << 8) | (cbuf[0] << 0);
      cbuf += 4;

      if (csize < dsize) {
        std::printf("decompress: csize: %x, dsize: %x\n", csize, dsize);
        size_t bsize = dsize;
        decompress_block(csize, cbuf, dbuf, &bsize);
        std::printf("decompress: bsize: %x\n", bsize);
        // assert(bsize == dsize);
      } else {
        std::memcpy(dbuf, cbuf, csize);
      }

      cbuf += csize;
      dbuf += dsize;
      args.dsize += dsize;
      block++;
    }

    return cbuf;
  } else {
    std::memcpy(args.dbuffer, args.cbuffer, dblock_size * bcount);
    args.dsize = dblock_size * bcount;
    return args.cbuffer + args.dsize;
  }
}
#define log(message)                                                        \
  std::printf(message                                                       \
              ", count: %x, dbuf: %x, cbuf: %x, cend: %x, sref: %x, lref: " \
              "%x, %s:%d\n",                                                \
              count,                                                        \
              dbuf - dbuffer,                                               \
              cbuf - cbuffer,                                               \
              cend - cbuffer,                                               \
              sref - dbuffer,                                               \
              lref - dbuffer,                                               \
              __FILE__,                                                     \
              __LINE__)
int decompress_block(size_t   csize,
                     uint8_t* cbuffer,
                     uint8_t* dbuffer,
                     size_t*  bsize) {
#define copy(dst, src, count)     \
  do {                            \
    assert(count > 0);            \
    std::memcpy(dst, src, count); \
    dst += count;                 \
    src += count;                 \
    count = 0;                    \
  } while (0)

#define copy4(dst, src, count)         \
  do {                                 \
    assert((count & ~3) > 0);          \
    std::memcpy(dst, src, count & ~3); \
    dst += count & ~3;                 \
    src += count & ~3;                 \
    count &= 3;                        \
  } while (0)

#define copyn(dst, src, count, n, m) \
  do {                               \
    assert(count > 0);               \
    std::memcpy(dst, src, n);        \
    dst += n;                        \
    src += n;                        \
    count -= m;                      \
  } while (0)

#define countz(cbuf, count, value) \
  do {                             \
    count &= value;                \
    if (count == 0) {              \
      while (cbuf[0] == 0) {       \
        count += 0xff;             \
        cbuf++;                    \
      }                            \
      count += cbuf[0] + value;    \
      cbuf++;                      \
    }                              \
  } while (0)

  uint8_t* cbuf = cbuffer;
  uint8_t* cend = cbuf + csize;
  uint8_t* dbuf = dbuffer;
  uint8_t* sref = dbuffer;
  uint8_t* lref = dbuffer;
  *bsize        = 0;

  int count = cbuf[0];
  if (count <= 0x11) goto l42a57b;
  count -= 0x11;
  cbuf++;
  if (count < 4) goto l42a630;
  copy(dbuf, cbuf, count);
  goto l42a5ea;

l42a57b:
  count = cbuf[0];
  cbuf++;
  if (count >= 0x10) goto l42a63d;
  countz(cbuf, count, 0xf);
  copyn(dbuf, cbuf, count, 4, 1);
  if (count == 0) goto l42a5ea;
  if (count < 4) goto l42a5e1;
  copy4(dbuf, cbuf, count);
  if (count <= 0) goto l42a5ea;
  copy(dbuf, cbuf, count);
  goto l42a5ea;
l42a5e1:
  copy(dbuf, cbuf, count);

l42a5ea:
  count = cbuf[0];
  cbuf++;
  if (count >= 0x10) goto l42a63d;
  sref = dbuf - count / 4 - cbuf[0] * 4 - 0x801;
  cbuf++;
  dbuf[0] = sref[0];
  dbuf++;
  sref++;

l42a613:
  dbuf[0] = sref[0];
  dbuf[1] = sref[1];
  dbuf++;
  dbuf++;

l42a61e:
  count = cbuf[-2] & 3;
  if (count == 0) goto l42a57b;

l42a630:
  copy(dbuf, cbuf, count);
  count = cbuf[0];
  cbuf++;

l42a63d:
  if (count < 0x40) goto l42a67b;
  lref = dbuf - ((count / 4) & 7) - (cbuf[0] * 8) - 1;
  count /= 32;
  cbuf++;
  count--;

l42a65c:
  dbuf[0] = lref[0];
  dbuf[1] = lref[1];
  dbuf++;
  lref++;
  dbuf++;
  lref++;
  copy(dbuf, lref, count);
  goto l42a61e;

l42a67b:
  if (count < 0x20) goto l42a6b6;
  countz(cbuf, count, 0x1f);
  lref = dbuf;
  lref -= ((cbuf[0] << 0) | (cbuf[1] << 8)) / 4;
  cbuf += 2;
  lref--;
  goto l42a700;

l42a6b6:
  if (count < 0x10) goto l42a74e;
  lref = dbuf - (count & 8) * 2048;
  countz(cbuf, count, 7);
  lref -= ((cbuf[0] << 0) | (cbuf[1] << 8)) / 4;
  cbuf += 2;
  if (lref - dbuf == 0) {
    *bsize = dbuf - dbuffer;
    if (cbuf - cend != 0)
      return -4;
    else
      return 0;
  }
  lref -= 0x4000;

l42a700:
  if (count < 6) goto l42a65c;
  if (dbuf - lref < 4) goto l42a65c;
  copyn(dbuf, lref, count, 4, 2);
  copy4(dbuf, lref, count);
  if (count <= 0) goto l42a61e;
  copy(dbuf, lref, count);
  goto l42a61e;

l42a74e:
  sref = dbuf - count / 4 - cbuf[0] * 4 - 1;
  cbuf++;
  goto l42a613;
}

struct BIGHeader {
  char     type[4];
  uint32_t u000;
  uint32_t file_count;
  uint32_t folder_count;
  uint32_t u001;
  uint32_t u002;
  uint32_t u003;
  uint32_t u004;
  uint32_t file_capacity;
  uint32_t u005;
  uint32_t u006;
  uint32_t file_count_bis;
  uint32_t u007;
  uint32_t offset;
  uint32_t u008;
  uint32_t u009;
  uint32_t u010;
};

struct BIGEntry {
  uint32_t offset;
  uint32_t id;
};

struct BIGFile {
  uint32_t size;
  uint32_t next;
  uint32_t prev;
  uint32_t folder;
  uint32_t timestamp;
  char     name[64];
};

struct BIGFolder {
  uint32_t id;
  uint32_t child;
  uint32_t next;
  uint32_t prev;
  uint32_t parent;
  char     name[64];
};

int main(int argc, char const* argv[]) {
  {
    uint8_t cbuffer[] = {
      0xEA, 0x01, 0x00, 0x00, 0xF3, 0x00, 0x00, 0x00, 0x0D, 0x08, 0x00, 0x00,
      0x00, 0x1D, 0x63, 0x00, 0x5E, 0x2E, 0x77, 0x6F, 0x77, 0xB4, 0x00, 0x00,
      0x00, 0x7E, 0x00, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x00,
      0x5F, 0x6D, 0x61, 0x69, 0x6E, 0x5F, 0x6E, 0x65, 0x77, 0x67, 0x61, 0x6D,
      0x65, 0x00, 0x77, 0x6F, 0x77, 0xC8, 0x03, 0x20, 0x05, 0x1A, 0x00, 0x80,
      0x3F, 0x30, 0x9C, 0x00, 0x20, 0x09, 0x4D, 0x00, 0x06, 0x90, 0x07, 0xDE,
      0x05, 0xFC, 0xFC, 0x95, 0x01, 0xFF, 0xC0, 0x00, 0x01, 0x1C, 0x63, 0x00,
      0x5E, 0x60, 0x02, 0x06, 0xE2, 0x02, 0x05, 0x12, 0x04, 0x00, 0x00, 0x00,
      0x29, 0x4D, 0x18, 0x9E, 0x7F, 0x17, 0x67, 0x61, 0x6F, 0x7C, 0x02, 0x02,
      0xA0, 0x20, 0x00, 0x00, 0x23, 0x62, 0x01, 0x10, 0x83, 0x75, 0x00, 0x00,
      0xD4, 0x08, 0x8C, 0x01, 0xF0, 0x00, 0x38, 0x4C, 0x00, 0x01, 0xBB, 0xD6,
      0x99, 0xBE, 0x4C, 0x00, 0x07, 0x3E, 0x00, 0x00, 0xA0, 0x40, 0x00, 0x00,
      0x80, 0x3F, 0x02, 0x8A, 0x06, 0x80, 0xBF, 0x4C, 0x01, 0xEC, 0x00, 0x44,
      0x1B, 0x7E, 0x07, 0x80, 0x3F, 0x60, 0x12, 0x78, 0x03, 0xFF, 0x00, 0x00,
      0x00, 0x7F, 0x5D, 0x11, 0x31, 0x5C, 0x11, 0x06, 0x0E, 0x00, 0x00, 0x00,
      0x57, 0x50, 0x5F, 0x61, 0x69, 0x6D, 0x27, 0x2E, 0x61, 0x13, 0x08, 0x45,
      0x02, 0x2F, 0x45, 0x17, 0x30, 0x4D, 0x00, 0x10, 0x74, 0x15, 0x54, 0x04,
      0x02, 0x2E, 0x6F, 0x76, 0x61, 0x2D, 0x9F, 0x00, 0x66, 0x63, 0x20, 0x60,
      0x09, 0x3D, 0x0D, 0x00, 0x24, 0x2D, 0x7C, 0x00, 0x6C, 0x07, 0x2D, 0x48,
      0x00, 0x98, 0x01, 0x0D, 0x0C, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
      0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00,
    };

    uint8_t dbuffer[] = {
      0x08, 0x00, 0x00, 0x00, 0x1D, 0x63, 0x00, 0x5E, 0x2E, 0x77, 0x6F, 0x77,
      0xB4, 0x00, 0x00, 0x00, 0x2E, 0x77, 0x6F, 0x77, 0x03, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x5F, 0x6D, 0x61, 0x69,
      0x6E, 0x5F, 0x6E, 0x65, 0x77, 0x67, 0x61, 0x6D, 0x65, 0x00, 0x77, 0x6F,
      0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F,
      0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
      0x00, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
      0x00, 0x00, 0x00, 0x00, 0x1C, 0x63, 0x00, 0x5E, 0x00, 0x00, 0x00, 0x00,
      0xE2, 0x02, 0x05, 0x12, 0x04, 0x00, 0x00, 0x00, 0x29, 0x63, 0x00, 0x5E,
      0x9E, 0x00, 0x00, 0x00, 0x2E, 0x67, 0x61, 0x6F, 0x00, 0x00, 0x00, 0x00,
      0xA0, 0x20, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x10, 0x83, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00,
      0x00, 0x00, 0xBB, 0xD6, 0x99, 0xBE, 0xBB, 0xD6, 0x99, 0x3E, 0x00, 0x00,
      0xA0, 0x40, 0x00, 0x00, 0x80, 0x3F, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x80, 0xBF, 0x00, 0x00, 0x80, 0xBF, 0x00, 0x00, 0x80, 0xBF, 0x00, 0x00,
      0x00, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0xFF, 0xFF,
      0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x31, 0x63, 0x00, 0x5E,
      0x0E, 0x00, 0x00, 0x00, 0x57, 0x50, 0x5F, 0x61, 0x69, 0x67, 0x61, 0x6D,
      0x65, 0x2E, 0x67, 0x61, 0x6F, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2F, 0x63,
      0x00, 0x5E, 0x30, 0x63, 0x00, 0x5E, 0x10, 0x00, 0x00, 0x00, 0x2E, 0x63,
      0x00, 0x5E, 0x2E, 0x6F, 0x76, 0x61, 0x2D, 0x63, 0x00, 0x5E, 0x2E, 0x6F,
      0x66, 0x63, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2D, 0x63, 0x00, 0x5E, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x04, 0x00,
      0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    size_t dsize = (cbuffer[0] << 0) | (cbuffer[1] << 8) | (cbuffer[2] << 16)
                   | (cbuffer[3] << 24);
    size_t csize = (cbuffer[4] << 0) | (cbuffer[5] << 8) | (cbuffer[6] << 16)
                   | (cbuffer[7] << 24);

    decompress_args args;
    args.dbuffer = new uint8_t[dsize];
    std::memset(args.dbuffer, 0, dsize);

    args.cbuffer = new uint8_t[csize + 8];
    std::memcpy(args.cbuffer, cbuffer, csize + 8);

    args.dsize = 0;
    decompress(args, 1);
    assert(std::memcmp(args.dbuffer, dbuffer, dsize) == 0);

    delete[] args.cbuffer;
    delete[] args.dbuffer;
  }

  {
    auto in = std::fopen(argv[1], "rb");

    auto header = BIGHeader{};
    std::fread(&header, 1, sizeof(header), in);

    auto entries = std::vector< BIGEntry >{};
    entries.resize(header.file_count);

    auto files = std::vector< BIGFile >{};
    files.resize(header.file_count);

    auto folders = std::vector< BIGFolder >{};
    folders.resize(header.folder_count);

    std::fseek(in, sizeof(BIGHeader), SEEK_SET);
    for (auto& entry : entries) {
      std::fread(&entry, 1, sizeof(entry), in);
    }

    std::fseek(in,
               sizeof(BIGHeader) + header.file_capacity * sizeof(BIGEntry),
               SEEK_SET);
    for (auto& file : files) {
      std::fread(&file, 1, sizeof(file), in);
    }

    std::fseek(in,
               sizeof(BIGHeader) + header.file_capacity * sizeof(BIGEntry)
                 + header.file_capacity * sizeof(BIGFile),
               SEEK_SET);
    for (auto& folder : folders) {
      std::fread(&folder, 1, sizeof(folder), in);
    }

    auto make_path = [&](BIGFile const& file) {
      auto split = std::vector< std::string >{};
      auto i     = file.folder;
      while (i != 0xffffffff) {
        split.push_back(folders[i].name);
        i = folders[i].parent;
      }

      std::reverse(split.begin(), split.end());
      auto path = std::string{"."};
      for (auto& name : split) {
        path += "/" + name;
        ::mkdir(path.c_str(), 0755);
      }

      return path + "/" + file.name;
    };

    std::printf("%d\n", header.file_count);
    std::printf("%d\n", header.folder_count);
    for (auto& file : files) {
      auto i    = &file - &files[0];
      auto path = make_path(file);

      auto buffer = std::vector< uint8_t >{};
      buffer.resize(file.size);
      std::fseek(in, entries[i].offset + 4, SEEK_SET);
      std::fread(&buffer[0], 1, file.size, in);

      size_t dsize = (buffer[0] << 0) | (buffer[1] << 8) | (buffer[2] << 16)
                     | (buffer[3] << 24);
      size_t csize = (buffer[4] << 0) | (buffer[5] << 8) | (buffer[6] << 16)
                     | (buffer[7] << 24);

      if (0 && path.substr(path.size() - 4) == ".bin" && csize <= file.size) {
        size_t coffset = 0;
        auto   out     = std::fopen((path + ".dec").c_str(), "w");

        while (coffset < file.size) {
          size_t dsize = (buffer[coffset + 0] << 0) | (buffer[coffset + 1] << 8)
                         | (buffer[coffset + 2] << 16)
                         | (buffer[coffset + 3] << 24);
          size_t csize = (buffer[coffset + 4] << 0) | (buffer[coffset + 5] << 8)
                         | (buffer[coffset + 6] << 16)
                         | (buffer[coffset + 7] << 24);
          if (csize == 0 || dsize == 0) break;

          decompress_args args;
          args.cbuffer = &buffer[coffset + 0];
          args.dbuffer = new uint8_t[dsize];
          std::memset(args.dbuffer, 0, dsize);

          args.dsize = 0;
          decompress(args, 1);
          coffset += csize + 8;

          std::fwrite(args.dbuffer, 1, dsize, out);

          delete[] args.dbuffer;
        }

        std::fflush(out);
        std::fclose(out);
      }

      {
        auto out = std::fopen(path.c_str(), "wb");
        std::fwrite(&buffer[0], 1, file.size, out);
        std::fflush(out);
        std::fclose(out);
      }

      {
        auto out = std::fopen((path + ".id").c_str(), "w");
        std::fprintf(out, "%08x", entries[i].id);
        std::fflush(out);
        std::fclose(out);
      }

      std::printf("%s\n", path.c_str());
    }
  }

  return 0;
}
