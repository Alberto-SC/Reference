import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n = int(input())

  start = n//2
  used = [False]*(n+1)

  ans = []
  while not used[start] and start>=1:
    used[start] = True
    aux = start
    start*=2 
    while 1:
      used[start] = True
      ans.append(start)
      if start %2: break
      start//=2

    start = aux-1

  for i in range(1,n+1):
    if not used[i]:
      ans.append(i)

  print(*ans)
