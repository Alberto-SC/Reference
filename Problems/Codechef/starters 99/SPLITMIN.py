# cook your dish here
for _ in range(int(input())):
    n = int(input())
    pairs = []
    m = 0
    
    for i in range(n):
        a,b = [int(x) for x in input().split()]
        pairs.append((a,i))
        pairs.append((b,i))
        m = max(m,min(a,b))
        
    ans = 10**12
    pairs.sort()
    for i in range(2*n):
        if pairs[i][0]<m: continue 
    
        if pairs[i][1] == pairs[i-1][1]: 
            ans = min(ans,pairs[i][0]-pairs[i-2][0])
            
        else: 
            ans = min(ans,pairs[i][0]-pairs[i-1][0])
        
    print(ans)