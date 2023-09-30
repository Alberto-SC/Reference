import sys
input = sys.stdin.readline

n = int(input())

ans = [['.']*((2*n)-1) for _ in range(n)]

ans[0][n-1] = "*"

for i in range(1,n):
  for j in range(0,2*n-1):
    cont = 0 
    if j-1>=0 and ans[i-1][j-1] == "*": cont+=1
    if j+1<2*n-1 and ans[i-1][j+1] == "*": cont+=1

    if cont == 1:
      ans[i][j] = "*"


for row in range(n):
  print("".join(ans[row]),end="\n")
