from construct import *

Dat = Struct("file",
        Pointer(lambda ctx: -28,
          Struct("footer",
            Bytes("uuid", 16),
            Magic("1TAD"),
            ULInt32("filenames_size"),
            ULInt32("index_size")
          )
        ),
        Pointer(lambda ctx: -ctx.footer.index_size,
          Struct("index",
            ULInt32("count"),
            Array(lambda ctx: ctx.count,
              Struct("file",
                ULInt32("length"),
                CString("name"),
                Padding(lambda ctx: ctx.length - len(ctx.name) - 1),
                ULInt32("name_address"),
                Enum(ULInt32("flags"), NONE = 1, ZLIB = 2, FOLDER = 1024),
                ULInt32("unpacked_size"),
                ULInt32("packed_size"),
                ULInt32("offset"),

                OnDemand(Pointer(lambda ctx: ctx.offset, Bytes("contents", lambda ctx: ctx.packed_size if ctx.flags == 'ZLIB' else ctx.packed_size))),
              )
            )
          )
        )
      )
