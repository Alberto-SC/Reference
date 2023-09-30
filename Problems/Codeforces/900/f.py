import sys
from collections import Counter
input = sys.stdin.readline

N = 10**6 +7
lp = [0]*(N+1)
primes = []

for i in range(2,N+1):
  if lp[i] == 0: 
    lp[i] = i
    primes.append(i)

  for j in range(len(primes)):
    if i*primes[j]>N:break 
    if primes[j]>lp[i]: break 

    lp[primes[j]*i] = primes[j]




for _ in range(int(input())):
  n,q= map(int,input().split())
  F = Counter()

  while n>1: 
    F[lp[n]]+=1 
    n//=lp[n]

  firstF = F.copy()

  for _ in range(q):
    line = list(map(int,input().split()))
    t = 0
    x = 0
    if len(line) == 1:
      t = line[0]
    else :
      t = line[0]
      x = line[1]

    if t ==1: 
      aux = x 
    
      while aux>1:
        F[lp[aux]]+=1 
        aux//=lp[aux]

      divs = 1
      for k in F:
        divs*=(F[k]+1)
      
      md = 1 
      for k in F: 
        md*=(k**F[k])%divs
        md%=divs
      
      if len(F) == 0: 
        md = 0
      if md==0: 
        print("YES")
      else:
        print("NO")


    else :
      F = firstF.copy()
  print("")

    