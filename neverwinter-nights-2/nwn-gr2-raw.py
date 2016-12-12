#!/usr/bin/python

import sys

from construct import *

HexInt = lambda o: ExprAdapter(o, encoder=lambda o,c: o, decoder=lambda o,c: ("{:0x}").format(o))
PosProbe = lambda n: Probe(n, show_stream=True, show_context=False, show_stack=False, stream_lookahead=100)

StringEntry = lambda n: Struct(n, ULInt32("offset"), Pointer(lambda ctx: ctx.offset, CString("value")))
StringRef = lambda n: Struct(n,
    ULInt32("offset"),
    Anchor("default"),
    Pointer(lambda ctx: ctx.offset if ctx.offset > 0 else ctx.default,
      StringEntry(n),
    ),
  )

Gr2Raw = Struct("file",
  ULInt32("version0"),
  ULInt32("version1"),
  ULInt32("file_name_offset"),
  Pointer(lambda ctx: ctx.file_name_offset, CString("file_name")),
  HexInt(ULInt32("u00-0")),
  HexInt(ULInt32("u00-1")),
  HexInt(ULInt32("u01-0")),
  HexInt(ULInt32("u01-1")),
  HexInt(ULInt32("u02-0")),
  HexInt(ULInt32("u02-1")),
  HexInt(ULInt32("u03-0")),
  HexInt(ULInt32("u03-1")),
  HexInt(ULInt32("u04-0")),
  HexInt(ULInt32("u04-1")),
  HexInt(ULInt32("u05-0")),
  HexInt(ULInt32("u05-1")),
  HexInt(ULInt32("u06-0")),
  HexInt(ULInt32("u06-1")),
  HexInt(ULInt32("u07-0")),
  HexInt(ULInt32("u07-1")),
  HexInt(ULInt32("u08-0")),
  HexInt(ULInt32("u08-1")),
  HexInt(ULInt32("u09-0")),

  ULInt32("creator_name_offset_offset"),
  StringEntry("creator_name"),
  Magic("\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\xc8\x42\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x3f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x3f\x00\x00\x00\x00\x00\x00\x80\xbf"),
  ULInt32("exporter_name_offset_offset"),
  StringEntry("exporter_name"),
  Magic("\x02\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\n\x00\x00\x00"),

  ULInt32("name_offset_offset"),
  Pointer(lambda ctx: ctx.name_offset_offset,
    Struct("listhead",
      StringEntry("name"),
      ULInt32("count"),
      ULInt32("offset_offset"),
      StringEntry("name2"),
    ),
  ),

Pointer(lambda ctx: 0xb4,
  Struct("list",
  )),

  PosProbe("probe"),
)

with open(sys.argv[1], 'rb') as stream:
  print >>sys.stderr, sys.argv[1]
  raw = Gr2Raw.parse_stream(stream)
  print raw
