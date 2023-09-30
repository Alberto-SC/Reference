import math
import sys

t= int(input());

for i in range(0,t):
    n= int(input());
    total = (n*(n-1))//2
    wins = 0
    for i in range (total,1):
        if (i*3)+((total-i)*2)%n ==0:
            wins = i
            break

    points = ((i*3)+((total-i)*2))/n
    arr = [n]
    for i in range (0,n-1):
        arr[i] = points
    
    if n&1:
        for i in range (0,n):
            for j in range (i+1,n):
                if arr[i]>=3:
                    arr[i] = arr[i]-3
                    print(1,end = ' ')
                elif arr[j]>=3:
                    arr[j] = arr[j]-3
                    print(-1,end = ' ')
    else:
        ans = [n]
        for i in range (0,n-1):
            ans[i] = [n]
        for i in range (0,(n//2)-1):
            ans[i][i+(n//2)] = 0
        for i in range (1,(points-1)//3):
            for j in range(0,n-1):
                ans[j][(j+i)%n] =1

        for i in range(0,n-1):
            for j in range(i+1,n-1):                
                print(ans[i][j],end = ' ')
        print("\n")