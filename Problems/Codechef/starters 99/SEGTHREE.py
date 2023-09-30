from itertools import product

for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
  ans = 10**9

  for x,y in product([0,1,2],repeat=2):
    res = x+y
    copy = a[:]
    copy[0]+=x
    copy[1]+=y

    for i in range(2,n):
      sum = copy[i]+copy[i-1]+copy[i-2]
      sum%=3

      if sum: 
        res+=3-sum
        copy[i]+=3-sum

    ans = min(ans,res)

  print(ans)