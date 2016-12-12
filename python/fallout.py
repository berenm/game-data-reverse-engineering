#!/usr/bin/python

import os
import sys

import lzss

sys.path.append('construct')
from format.fallout import *

class DatFile:
  def __init__(self, filename):
    self.__filename = filename
    self.__file = open(filename, 'rb')
    self.__dict__.update(Dat.parse_stream(self.__file).__dict__)


  def unpack(self, target):
    for i,d in enumerate(self.folder):
      d = os.path.join(*d.split('\\'))

      for j,f in enumerate(self.filelist[i].file):
        targetfile = os.path.join(target, d, f.name).lower()
        targetdir  = os.path.d(targetfile).lower()

        print 'Extracting %s...' % targetfile

        if not os.path.exists(targetdir):
          os.makedirs(targetdir)

        if f.flags == 'NONE':
          with open(targetfile, 'wb') as o:
            o.write(f.contents.value)
        else:
          with open(targetfile, 'wb') as o:
            lzss2.decompress_string(f.contents.value, o)


  def list(self):
    for i,d in enumerate(self.folder):
      d = os.path.join(*d.split('\\'))

      for j,filename in enumerate([ f.name for f in self.filelist[i].file ]):
        print os.path.join(d, filename)


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
