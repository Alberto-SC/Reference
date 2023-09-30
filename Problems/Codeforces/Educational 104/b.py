import math
import sys

t= int(input());

for i in range(0,t):
    n,k = input().split()
    n = int(n)
    k = int(k)
    init = 1
    k = k-1
    x = n//2
    if n&1:
        y = k//x
        init = init+((x+1)*y)
        init = init+ (k%x)
        if init%n == 0:
            print(n)
        else:
            print(init%n)
    else:
        init = init+k
        if init%n == 0:
            print(n)
        else: 
            print(init%n)