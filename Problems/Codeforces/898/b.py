import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n = int(input())
  a = list(map(int,input().split()))

  res = 0
  for i in range(n):
    a[i]+=1 
    ans= 1 
    for x in a: 
      ans*=x
    a[i]-=1
    res = max(res,ans)
  print(res)
