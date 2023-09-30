import sys

def DP[3000][3000];

def s(x, a):
	if x == 0 or x == 1 :
		return  floor((a*a)/2)
	if a == 0 or a == 1:
		return floor((2*x)/3)
	if DP[x][a] != -100 : 
		return DP[x][a]
	DP[x][a] = (s(x+1,a-2) + s(x-2,a+1))%pow(2,32)
	return DP[x][a]%pow(2,32)


x = int(input())
a = int(input())
cin>>x>>a
for i in range(0, 2*x):
	for j in range(0, 2*a):
			DP[i][j] = -100
	
print(s(x,a)%p)

