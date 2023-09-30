t = int(input())
array = []
ans = 1
for i in range(1,41):
	ans*=i
	array.append(ans)
for i in range(0,t):
	n = int(input())
	print(array[n-1])