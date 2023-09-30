a,b = input().split()
a = int(a)
b = int(b)
x = abs((b-1)-a)
if x<a :
    print(int((a-x)/2))
else :
    print(0)