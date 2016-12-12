#!/usr/bin/python

import os
import sys
import zlib


sys.path.append('construct')
from format.fallout2 import *

class DatFile:
  def __init__(self, filename):
    self.__filename = filename
    self.__file = open(filename, 'rb')
    self.__dict__.update(Dat.parse_stream(self.__file).__dict__)


  def unpack(self, target):
    for i,f in enumerate(self.index.file):
      targetfile = os.path.join(target, *f.name.split('\\')).lower()
      targetdir  = os.path.dirname(targetfile).lower()

      print 'Extracting %s...' % targetfile

      if not os.path.exists(targetdir):
        os.makedirs(targetdir)

      if f.flags == 'NONE':
        with open(targetfile, 'wb') as o:
          o.write(f.contents.value)
      else:
        with open(targetfile, 'wb') as o:
          o.write(zlib.decompress(f.contents.value))


  def list(self):
    for i,f in enumerate(self.index.file):
      print os.path.join(*f.name.split('\\'))


if __name__ == '__main__':
  if len(sys.argv) < 2:
    print """usage:
  - fallout-dat list <filename.dat>
  - fallout-dat unpack <filename.dat> <target>
"""

  else:
    if sys.argv[1] == 'list':
      DatFile(sys.argv[2]).list()

    elif sys.argv[1] == 'unpack':
      DatFile(sys.argv[2]).unpack(sys.argv[3] if len(sys.argv) > 3 else os.path.basename(sys.argv[2]))
