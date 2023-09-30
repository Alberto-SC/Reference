a,b,c,n = input().split()
a = int(a)
b = int(b)
c = int(c)
n = int(n)

comb = n
if(n & 1):
    comb = (n*n+n)*(n-1)
    comb = comb//24
else: 
    comb = (n*n+8*n)*(n-2)
    comb = comb//24


if a!=b and b!=c and c!=a:
    comb = comb*6
elif a!=b or b!=c or a!=c:
    comb = comb*3

mod = 2**64

print(comb%mod)
