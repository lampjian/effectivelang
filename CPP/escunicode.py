#!/usr/bin/env python

from __future__ import unicode_literals
import sys
import json
import codecs

def unescape_json(fname_in, fname_out):
    with file(fname_in, 'rb') as fin:
        js = json.load(fin)
    with codecs.open(fname_out, 'wb', 'utf-8') as fout:
        json.dump(js, fout, ensure_ascii=False)

def usage():
    print "Converts all \\uXXXX codes in json into utf-8"
    print "Usage: .py infile outfile"
    sys.exit(1)

def main():
    try:
        fname_in, fname_out = sys.argv[1:]
    except Exception:
        usage()

    unescape_json(fname_in, fname_out)
    print "Done."

if __name__ == '__main__':
    main()

