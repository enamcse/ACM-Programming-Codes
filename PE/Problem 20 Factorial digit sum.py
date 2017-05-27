#-------------------------------------------------------------------------------
# Name:        Problem 20: Factorial digit sum
# Purpose:     http://projecteuler.net/problem=20
#
# Author:      Enamul
#
# Created:     01/05/2014
# Copyright:   (c) Enamul 2014
# Licence:     <your licence>
#-------------------------------------------------------------------------------
from math import factorial
def main():
    pass

if __name__ == '__main__':
    main()
    a = factorial(100)
    b = str(a)
    x = 0;
    for y in b:
        x += int(y)
    print x
