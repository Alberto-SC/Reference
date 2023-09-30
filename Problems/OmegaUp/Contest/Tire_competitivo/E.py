import sys

query = sys.stdin.readline()
n,p = query.split()
p = int(p)
n = int(n)
print(pow(n, p))
