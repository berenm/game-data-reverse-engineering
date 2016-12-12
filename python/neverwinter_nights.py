#!/usr/bin/python

import os
import sys
import zlib


sys.path.append('construct')
from format.neverwinter_nights import *

class BiffFile:
  def __init__(self, filename):
    self.__filename = filename
    self.__file = open(filename, 'rb')
    self.__dict__.update(Biff.parse_stream(self.__file))


  def unpack(self, index, target):
    with open(target, 'wb') as o:
      o.write(self.variable_resource_entry[index].contents.value)


class KeyFile:
  def __init__(self, filename):
    self.__filename = filename
    self.__file = open(filename, 'rb')
    self.__dict__.update(Key.parse_stream(self.__file))


  def unpack(self, target):
    bifs = {}
    for i,f in enumerate(self.bif):
      bifs[f.filename] = BiffFile(os.path.join(os.path.dirname(self.__filename), *f.filename.split('\\')))

    for i,f in enumerate(self.res):
      bifname = self.bif[f.id >> 20].filename
      targetfile = os.path.join(os.path.join(*bifname.split('\\')), f.name) + '.' + Extension.get(f.type, str(f.type))
      targetdir = os.path.dirname(targetfile)

      print 'Extracting %s...' % targetfile

      if not os.path.exists(targetdir):
        os.makedirs(targetdir)

      bifs[bifname].unpack(f.id & ((1 << 20) - 1), targetfile)


  def list(self):
    for i,f in enumerate(self.res):
      targetfile = os.path.join(os.path.join(*self.bif[f.id >> 20].filename.split('\\')), f.name) + '.' + Extension.get(f.type, str(f.type))
      print targetfile


if __name__ == '__main__':
  if len(sys.argv) < 2:
    print """usage:
  - neverwinter-nights list <filename.dat>
  - neverwinter-nights unpack <filename.dat> <target>
"""

  else:
    if sys.argv[1] == 'list':
      KeyFile(sys.argv[2]).list()

    elif sys.argv[1] == 'unpack':
      KeyFile(sys.argv[2]).unpack(sys.argv[3] if len(sys.argv) > 3 else os.path.basename(sys.argv[2]))
