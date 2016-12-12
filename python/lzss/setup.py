from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
  name = 'lzss',
  cmdclass = {'build': build_ext},
  ext_modules=[ Extension("lzss", ["lzss.pyx"]) ]
)
