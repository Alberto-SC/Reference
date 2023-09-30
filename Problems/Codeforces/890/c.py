import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n,k = map(int, input().split())
  nums = list(map(int, input().split()))

  nums.append(-10**9)
  def check(x):
    aux = x
    for i in range(n+1):
      need = 0
      x = aux
      for j in range(i,n+1):
        if nums[j]<x: 
          need+=x-nums[j]
          x-=1
        else: 
          break 
      if need<=k:  return True

    return False
  
  l,r = (max(nums),10**9)
  while l+1<r:
    m = (l+r)>>1

    if check(m): l = m 
    else: r = m

  print(l)
