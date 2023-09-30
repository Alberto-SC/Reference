import sys
input = sys.stdin.readline

for _ in range(int(input())):
  s = input().strip()

  if s in ["abc","bac","cba","acb"]:
    print("YES")
  else: 
    print("NO")