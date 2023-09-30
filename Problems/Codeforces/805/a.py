from sys import stdin, stdout
for tc in range(int(stdin.readline())):
    n = int(stdin.readline())
    x = 1
    while(x <=n): 
        x*=10
    
    x//=10
    print(n-x)