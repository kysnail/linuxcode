#!/usr/bin/python
#/home/python/Python-2.5.6/python

def lines(file):
        for line in file: yield line
        yield '\n'

def blocks(file):
        block = []
        for line in lines(file):
                if line.strip():
                        block.append(line)
                elif block:
                        yield ''.join(block).strip()
                        block = []
