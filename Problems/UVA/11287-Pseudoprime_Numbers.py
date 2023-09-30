import sys
for query in sys.stdin:
	exp, number = query.split()
	exp = int(exp)
	number = int(number)
	if not(number and exp):
		break
	if (pow(number, exp))%exp == number:
		print("yes")
	else:
		print("no")
