import sys
input = sys.stdin.readline

for _ in range(int(input())):
  ans = 0
  for i in range(10):
    s = input().strip()
    R1 = i+1 if i<=4 else 10-i

    for j in range(10):
      R2 = j+1 if j<=4 else 10-j
      if s[j] == 'X':
        ans += min(R1,R2)

  print(ans)