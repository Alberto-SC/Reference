import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    idx = len(a)-2
    while idx>=0 and a[idx]<=a[idx+1]:
      idx-=1

    if idx<0: 
      print(0)
    else : 
      print(max(a[:idx+1]))



      
