#!/usr/bin/python

import time
import ctypes
from pwn import *

e = ELF("./prob")
p = process(e.path)
l = ctypes.CDLL(e.libc.path)

def solve():
    seed = int(p.readuntil("\n").split(": ")[-1])
    l.srand(seed)
    for _ in xrange(10):
        p.sendline(str(l.rand()))
    p.interactive()

if __name__ == "__main__":
    solve()