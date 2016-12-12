from construct import *

Dat = Struct("file",
        Struct("header",
          UBInt32("folder_count"),
          UBInt32("unknown_1"),
          UBInt32("unknown_2"),
          UBInt32("timestamp")
        ),

        Array(lambda ctx: ctx.header.folder_count,
          PascalString("folder", length_field=UBInt8("length"))
        ),

        Array(lambda ctx: ctx.header.folder_count,
          Struct("filelist",
            UBInt32("count"),
            UBInt32("unknown"),
            UBInt32("flags"),
            UBInt32("timestamp"),

            Array(lambda ctx: ctx.count,
              Struct("file",
                PascalString("name", length_field=UBInt8("length")),
                Enum(UBInt32("flags"), NONE = 32, LZSS = 64),
                UBInt32("offset"),
                UBInt32("unpacked_size"),
                UBInt32("packed_size"),

                OnDemand(Pointer(lambda ctx: ctx.offset, Bytes("contents", lambda ctx: ctx.packed_size if ctx.flags == 'LZSS' else ctx.unpacked_size))),
              )
            )
          )
        )
      )
