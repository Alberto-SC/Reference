import sys
input = sys.stdin.readline
from itertools import accumulate

for _ in range(int(input())):
  n,k = map(int,input().split())
  a = list(map(int,input().split()))
  h = list(map(int,input().split()))

  ranges = [0]*n
  last = 0
  for i in range(1,n):
    if h[i-1]%h[i]:
      for j in range(last,i): 
        ranges[j] = i-1 
      last = i 
  for j in range(last,n):
    ranges[j] = n-1

  v = list(accumulate(a))

  ans = 0
  for i in range(n):
    L = i-1
    R = ranges[i]+1
    while L+1<R:
      mid = (L+R)//2

      sum = v[mid]-(v[i-1] if i>0 else 0)
      if sum <= k:
        L = mid 
      else:
        R = mid

    if(L>=i):
      ans = max(ans,(L-i)+1)

  print(ans)