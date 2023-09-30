t = int(input())

for test in range(0,t):
    n = int(input())
    sum = 1
    for j in range(1,n+1):
        print(j)
        sum = sum*j
    print(sum)
