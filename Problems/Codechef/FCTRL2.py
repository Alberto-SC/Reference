t = int(input())
while(t):
    n = int(input())
    ans = 1
    for i in range(2,n+1):
        ans = ans*i
    print(ans)
    t = t-1