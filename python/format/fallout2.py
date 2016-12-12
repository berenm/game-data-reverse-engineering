from construct import *

Dat = Struct("file",
        Pointer(lambda ctx: -8,
          Struct("footer",
            ULInt32("index_size"),
            ULInt32("file_size")
          )
        ),
        Pointer(lambda ctx: -8 - ctx.footer.index_size,
          Struct("index",
            ULInt32("count"),
            Array(lambda ctx: ctx.count,
              Struct("file",
                PascalString("name", length_field=ULInt32("length")),
                Enum(ULInt8("flags"), NONE = 0, ZLIB = 1),
                ULInt32("unpacked_size"),
                ULInt32("packed_size"),
                ULInt32("offset"),

                OnDemand(Pointer(lambda ctx: ctx.offset, Bytes("contents", lambda ctx: ctx.unpacked_size if ctx.flags == 'NONE' else ctx.packed_size))),
              )
            )
          )
        )
      )
