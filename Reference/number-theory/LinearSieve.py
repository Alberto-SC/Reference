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
 