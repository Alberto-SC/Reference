import sys
from itertools import accumulate
input = sys.stdin.readline

for _ in range(int(input())):
  s = input().strip()
  n = len(s)
  last = -1 
  first = -1
  flag = False
  B = []
  for i in range(n):
    if s[i] == 'B': 
      B.append(i)
      last = i

  for i in range(n-1,-1,-1):
    if s[i] == 'B':
      first = i

  vpref = list(accumulate([1 if s[i] == 'A' else 0 for i in range(n)]))
  vsuff = list(accumulate([1 if s[i] == 'A' else 0 for i in range(n-1,-1,-1)]))[::-1]
  if first ==-1:
    print(0)
  else: 
    ans = max(vsuff[first],vpref[last])
    for i in range(len(B)-1):
      ans = max(ans,vpref[B[i]]+vsuff[B[i+1]])
    print(ans)

  