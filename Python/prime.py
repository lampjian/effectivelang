#!/usr/bin/env python
# -*- coding: utf-8 -*-

def _odd_iter():
    n = 1
    while True:
        n = n+2
        yield n

def _not_divisible(n): #
    return lambda x:x%n>0

def primes():
    yield 2
    it = _odd_iter() # initial series
    print(it)
    while True:
        n = next(it) # first number of series
        yield n
        it = filter(_not_divisible(n),it) # construct new series
        # print(it)
    for n in primes():
        if n<1000:
            print(n)
        else:
            break;

def main():
    primes()

if __name__ == '__main__':
    main()

