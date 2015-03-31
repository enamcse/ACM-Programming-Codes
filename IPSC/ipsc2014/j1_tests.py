#-------------------------------------------------------------------------------
# Name:        nCr
# Purpose:
#
# Author:      Enamul
#
# Created:     15/06/2014
# Copyright:   (c) Enamul 2014
# Licence:     <your licence>
#-------------------------------------------------------------------------------

nCr=[];

def now(n,  r):
    if(r==1):
        return n
    if(r==n):
        return 1
    if(nCr[n][r]!=-1):
        return nCr[n][r]
    nCr[n][r] = now(n-1,r-1) + now(n-1,r);
    return nCr[n][r]

def solve1(n, k):
    if k == 0 or n == k: return 1
    return solve1(n - 1, k) + solve1(n - 1, k - 1)

def solve2(n, k):
    dx = [ 1, 0, -1, 0]
    dy = [ 0,-1,  0, 1]
    def move(x, y, d):
        if x == k and y == n - k: return 1
        if d == 0: return 0
        sol = 0
        for i in range(4):
            sol += move(x + dx[i], y + dy[i], d - 1)
        return sol
    return move(0, 0, n)

def solve3(n, k):
    if n < 0 or k < 0 or k > n: return 0
    if n == 0 or k == 0 or n == k: return 1
    s = 0
    step = k
    if n > 47: step = 10
    for i in range(n + 1): # note: range(x) returns [0, 1, ..., x-1]
        s += solve3(n - step, i) * solve3(step, k - i)
    return s

def solve4(n, k):
    if n == 0 or k == 0: return 1
    s = 0
    for i in range(k - 1, n): s += solve4(i, k - 1) # note: range(x,y) returns [x,x+1,...,y-1]
    return s

def solve5(n, k):
    if n < 0 or k < 0 or k > n: return 0
    if n == 0 or k == 0: return 1
    s = 0
    for t in range(1, 20): s += solve5(n - t, k - 1)
    return s

def solve6(n, k):
    A = [ 0 for i in range(n+1) ]
    for s in range(16**n):        # note: ** is exponentiation, e.g., 2**5 == 32
        tmp = s
        odd = 0
        for t in range(n):
            if tmp % 2: odd += 1  # note: % is modulo, e.g., 7 % 3 == 1
            tmp = tmp // 16       # note: // is integer division, e.g., 7 // 3 == 2
        A[odd] += 1
    return A[k] // 2**(3*n)

def solve7(n, k):
    if k == 0 or n == k: return 1
    return solve7(n + 1, k) - solve7(n, k - 1)

def solve8(n, k):
    res = 1
    for i in range(n):     res = res *  (i + 1)
    for i in range(k):     res = res // (i + 1)
    for i in range(n - k): res = res // (i + 1)
    return res

def solve9(n, k):
    state = 47
    good = 0
    for step in range(8**n):
        heads = 0
        for i in range(n):
            state = ((state * 1103515245) + 12345) % 2**31
            coin = (state >> 15) & 1  # note: >> is bitwise shift right, & is bitwise and
            heads += coin
        if heads == k: good += 1
    return round(good / 4**n)         # note: / is floating-point division

from itertools import permutations

def solve10(n, k):
    brackets = '(' * n + ')' * n
    res = 0
    for perm in set(permutations(brackets)):
        # the following is executed once for each distinct permutation of our 2n brackets
        opened = 0
        maxopened = 0
        ok = True
        for b in perm:
            if b == '(': opened += 1
            if b == ')': opened -= 1
            if opened < 0: ok = False
            maxopened = max( opened, maxopened )
        if ok and maxopened == k: res += 1
    return res

def solve11(n, k):
    if k == 0 or n == k: return 1
    return solve11(n, k + 1) * (k + 1) // (n - k)



def main():
    arr =[0,0,0,0,1,0,1,0,1,1,0];

    em = [];

    for x in range(0,200):
        em.append(-1);
    print len(em)
    for x in range(0,200):
        nCr.append(list(em));

    for x in range(1,105):
        for y in range(1,x+1):
            now(x,y);
    flag = True;
    for x in range(20,21):
        for y in range(1,x+1):
            p =solve5(x,y)
            if(p!=now(x,y)):
                flag = False;
                print str(x) +' ' + str(y) + ' := '+str(p) +' should be '+ str(nCr[x][y])

    print flag

if __name__ == '__main__':
    main()
