import sys
input = sys.stdin.readline

n = int(input())
d,p,e = list(map(float,input().split()))

B = list(map(int,input().split()))


def getProb(x):
  P = []
  for b in B : 
    z = min(1,x/b)
    y = min(1,d*(x/b))
    print(z,y,b,x)
    P.append((p*y)+((1-p)*z))
  return P



P = getProb(1.92)

print(P)




