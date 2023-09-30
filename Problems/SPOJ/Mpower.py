import sys

def exp(a,b,m):
     r = 1
     while(b):
             if(b&1):
                r = (r*a)%m
             b>>=1
             a = ((a%m)*(a%m))%m
     return r

t = int(input())
while(t):
	t = t-1
	query = input()
	a,b,m = query.split()
	a = int(a)
	b = int(b)
	m = int(m)
	print(exp(a,b,m))