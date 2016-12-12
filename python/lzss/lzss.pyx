import struct

cdef int c_decompress_block(bytes ibuf, int ipos, int iend, bytes obuf, int opos, int oend):
  cdef int minlen = 3
  cdef int maxlen = 18
  cdef int dlen  = 4096

  dictionary = ' ' * dlen

  cdef int doff = 0
  cdef int dpos = dlen - maxlen
  cdef bytes dbuf = dictionary

  cdef int flags = 0
  while ipos < iend:
    flags = flags >> 1

    if flags & 0x100 == 0:
      if ipos == iend:
        break

      flags = ord(ibuf[ipos])
      flags = flags | 0xFF00
      ipos = ipos + 1


    if flags & 1:
      if ipos == iend:
        break

      if opos == oend:
        return -1

      dpos = dpos % dlen

      obuf[opos] = ibuf[ipos]
      dbuf[dpos] = ibuf[ipos]
      ipos = ipos + 1
      opos = opos + 1
      dpos = dpos + 1

    else:
      if ipos >= iend - 1:
        break

      doff = ord(ibuf[ipos])
      ipos = ipos + 1

      length = ord(ibuf[ipos])
      ipos = ipos + 1

      doff = doff | ((length & 0xF0) << 4)
      length = (length & 0x0F) + minlen

      for i in range(length):
        if opos == oend:
          return -1

        doff = doff % dlen
        dpos = dpos % dlen

        obuf[opos] = dbuf[doff]
        dbuf[dpos] = dbuf[doff]

        doff = doff + 1
        opos = opos + 1
        dpos = dpos + 1

  return opos


def decompress_block(ibuf, ipos, iend):
  output = '\0' * (2 << 15)
  cdef bytes obuf = output
  cdef int   olen = -1

  while olen < 0:
    olen = c_decompress_block(ibuf, ipos, iend, obuf, 0, len(obuf))
    if olen >= 0:
      break

    output = '\0' * (len(obuf) * 3 / 2)
    obuf   = output

  return ''.join(obuf[:olen])


def decompress_string(input, output):
  cdef int ipos = 0
  cdef int ilen = len(input)
  cdef int npos = 0
  cdef int rlen = 0
  cdef bytes ibuf = input

  while ipos < ilen:
    npos = ipos + 2
    rlen = struct.unpack(">h", ibuf[ipos:npos])[0]
    ipos = npos

    if rlen == 0:
      break

    elif rlen < 0:
      npos = ipos - rlen
      output.write(ibuf[ipos:npos])
      ipos = npos

    elif rlen > 0:
      npos = ipos + rlen
      output.write(decompress_block(ibuf, ipos, min(npos, ilen)))
      ipos = npos

  return output
