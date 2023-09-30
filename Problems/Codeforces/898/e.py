import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n,x = map(int,input().split())
  a = list(map(int,input().split()))

  L = 0
  R = 10**10

  while L+1<R:
    mid = (L+R)//2

    res = 0
    for i in range(n):
      res+=max(0,mid-a[i])

    if res<= x: 
      L = mid 
    else: 
      R = mid 
      

  print(L)