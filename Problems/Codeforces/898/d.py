import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n,x = map(int,input().split())

  s = input().strip()

  idx = 0 
  ans = 0
  while idx<n:
    if s[idx]== 'B': 
      ans+=1
      idx+=x
    else: 
      idx+=1

  ans2 = 0 
  idx = n-1
  while idx>=0:
    if s[idx] == 'B':
      ans2+=1
      idx-=x
    else: 
      idx-=1

    
  print(min(ans,ans2))