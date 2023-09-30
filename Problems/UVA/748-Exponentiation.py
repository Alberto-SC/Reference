import sys
for query in sys.stdin:
	decimal_number, exp = query.split()
	exp = int(exp)
	number = "" 
	result = ""
	digits_after_point = 0 
	flag = 0 
	exponentiation = 0 
	final_point = 0
	j = 0

	for i in range(len(decimal_number)):#find the point and create a number without it
		if(decimal_number[i] == '.'):	
			flag = 1
			digits_after_point = len(decimal_number) - i - 1
			number = decimal_number[:i] + decimal_number[i+1:]
			break;

	if(flag == 1):#Working with number where a point was found
		number = int(number)
		exponentiation = pow(number, exp)
		exponentiation = str(exponentiation)
		final_point = len(exponentiation) - (digits_after_point*exp)
			
		if(final_point < 0):#add zeroes to the left if the final point is negative
			result = "."  
			for i in range(abs(final_point)):
				result += "0"
			result += exponentiation

			j = len(result) -1#find a right limit boundary (eliminate zeroes at right)
			while(result[j] == '0'):
				j = j - 1
				
			if(result[j] == '.'):#eliminate the point if it is at the end
				result = result[:j]
			else:
				result = result[:j+1]

			print(result)	

		else:#if not just paste the point where it has to be
			result = exponentiation[:final_point] + "." + exponentiation[final_point:]
				
			j = len(result) -1#find a right limit boundary (eliminate zeroes at right)
			while(result[j] == '0'):
				j = j - 1
				
			if(result[j] == '.'):#eliminate the point if it is at the end
				result = result[:j]
			else:
				result = result[:j+1]

			print(result)
	else:#if there is a number without a point
		number = int(decimal_number)
		print(pow(number, exp))

