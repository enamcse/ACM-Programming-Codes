#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Enamul
# @Date:   2015-06-15 07:04:39
# @Last Modified by:   Enamul
# @Last Modified time: 2015-06-15 07:05:33
a,b,n = map(int,input().split());
if n == 1:
    print(a);
elif n == 2:
    print(b);
else:
    ans = 0;
    now = True;
    for x in range(2,n):
        if now:
            a = b*b + a;
            ans = a;
            now = False;
        else:
            b = a*a + b;
            ans = b;
            now = True;
    print(ans);