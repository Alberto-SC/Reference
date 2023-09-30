from math import factorial as fact

t = int(input())

for test in range(0,t):
    n = int(input())
    x = fact(n);
    sum = 0;
    while x:
        sum  = sum+ (x%10)
        x = x//10
    print(sum)
