import sys
input = sys.stdin.readline

for _ in range(int(input())):
  a,b,c =  map(int, input().split())

  if a>b or a ==b and c&1: 
    print("First")
  else : 
    print("Second")