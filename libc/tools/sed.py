#!/usr/bin/python

import sys

inp = sys.argv[1]
outp = sys.argv[2]
match = sys.argv[3]
repl = sys.argv[4]

with open(outp, "wt") as fout:
    with open(inp, "rt") as fin:
        for line in fin:
            fout.write(line.replace( match, repl ))
