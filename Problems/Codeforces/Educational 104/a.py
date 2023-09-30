import math
import sys

t= int(input());

for i in range(0,t):
    n = int(input())
    inp = input()
    arr = [int(x) for x in inp.split()]   
    arr.sort()
    mn = arr[0]
    cont = 0;
    for i in arr:
        if i == mn:
            cont = cont+1;
    print(n-cont)

