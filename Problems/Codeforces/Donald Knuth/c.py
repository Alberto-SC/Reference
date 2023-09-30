import sys
input = sys.stdin.readline
from itertools import *

for _ in range(int(input())):
    
    n = int(input())

    arr = list(map(int,input().split()))
    arr = [0 if x ==1 else 1 for x in arr]
    pref = list(accumulate(arr))


    ans = min(n-pref[-1],pref[-1])
    for i in range(n):
        R = n-i-1
        L = pref[i]
        x = pref[i]+(R-(pref[-1]-L))
        
        y = ((i+1)-pref[i])+(pref[-1]-L)
        ans = min(ans,x,y)

    print(ans,end=" ")