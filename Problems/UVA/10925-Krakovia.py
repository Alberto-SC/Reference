#NO JALO

import sys
import math
cont = 1
for query in sys.stdin:
	N,F = query.split()
	N = int(N)
	F = int(F)
	if not(N and F):
		break
	
	sum = 0
	p = 0
	for i in range(0,N):
		sum = sum+ int(input())
	p = sum/F
	#print(f'Bill # {cont} costs {sum}: each friend should pay {p}')
	print("Bill # ",cont," costs ",sum,": each friend should pay ",p, sep='')
	cont = cont+1