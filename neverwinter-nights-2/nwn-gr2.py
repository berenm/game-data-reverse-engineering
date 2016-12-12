#!/usr/bin/python

import sys

from construct import *

HexInt = lambda o: ExprAdapter(o, encoder=lambda o,c: o, decoder=lambda o,c: ("{:0x}").format(o))
PosProbe = lambda n: Probe(n, show_stream=True, show_context=False, show_stack=False, stream_lookahead=100)

Gr2 = Struct("file",
  Magic("\xb8\x67\xb0\xca\xf8\x6d\xb1\x0f\x84\x72\x8c\x7e\x5e\x19\x00\x1e"),
  ULInt32("flags"), # b8 01 00 00 : unprocessed
                    # 60 01 00 00 : processed
  Bytes("u0", 16),
  ULInt32("file_size"),
  HexInt(ULInt32("u1")),
  HexInt(ULInt32("u2")), # 38 00 00 00
  PosProbe("probe"),
)

with open(sys.argv[1], 'rb') as stream:
  print sys.argv[1]
  gr2 = Gr2.parse_stream(stream)
  print gr2
