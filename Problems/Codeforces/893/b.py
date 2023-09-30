import sys
from collections import Counter
input = sys.stdin.readline

for _ in range(int(input())):
  n,m,d = map(int,input().split())

  s = list(map(int,input().split()))

  if s[0] == 1: 
    total = 0   
    last = 1 
  else: 
    last = (s[0]-2)//d 
    total = last+1
    last = 1+(last*d)

  
  s.append(n+1)
  c = Counter()
  for i in range(m):
    dist1 = s[i+1]-last-1 
    dist2 = s[i+1]-s[i]-1

    r1 = dist1//d 
    r2 = dist2//d

    if(s[i]== 1):
      c[(r1+1)-(r2+1)]+=1
    else : 
      c[r1-(r2+1)]+=1

    last = s[i] + r2*d
    total += r2+1

  k = sorted(list(c.keys()))
  print(total+k[0],c[k[0]])
