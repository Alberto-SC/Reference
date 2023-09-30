import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n = int(input())
  nums = list(map(int, input().split()))

  cont = 0
  sum = 0
  for i in range(n):
    if nums[i]== 1: 
      cont+=1
    else :
      sum+=nums[i]-1

  if sum>=cont and n>1:
    print("YES")
  else: 
    print("NO")
