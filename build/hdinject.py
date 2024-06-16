#!/usr/bin/env python

'''
Python 3.x virtual environment required.
'''

from sys import argv
from sys import exit as sexit

if __name__ == '__main__':
    if len(argv) < 3:
        print('Arguments missed!')
        sexit(2)

    sf = open(argv[1], 'rb')
    sb = sf.read()
    sf.close()

    sb = b'\x01\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00' + sb
    df = open(argv[2], 'wb')
    df.write(sb)
    df.close()
