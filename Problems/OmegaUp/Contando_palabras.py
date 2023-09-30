import sys
for query in sys.stdin:
	st = query.split()
	n = 0
	yes = 0
	for s in st:
		for i in s:
			if (ord(i)>=65 and ord(i)<=90) or (ord(i)>=97 and ord(i)<=122):
				yes = 1
			if yes ==1:
					break
		if yes ==1:
			n = n+1
		yes = 0
	print(n)
	n = 0