t = int(input())
for _ in range(0,t):
    x,y = [int(x) for x in input().split()]
    
    if x**4 +(4*(y**2)) == 4*(x**2)*y:
        print("YES")
    else:
        print("NO")