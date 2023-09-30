dp = {}

s = []
z = []
def solve(idx,f):
    if idx == len(s): 
        return f 
        
    if (idx,f) in dp: 
        return dp[(idx,f)]
        
    ans = 0
    lim = s[idx] if f == 0 else  1 
    for i in range(lim+1):
        nwF = 1 if i<lim else f 
        
        if z[idx] == 0:
            need = z[idx]^s[idx]
            if i != need: continue 
            ans += solve(idx+1,nwF)
            
        else:
            ans += solve(idx+1,nwF)
            
    dp[(idx,f)] = ans 
    return dp[(idx,f)]
    
    
for _ in range(int(input())):
    N,X = map(int,input().split())
    
    strBinN = format(N,'b')
    strBinNedd = format(((1<<31)-1)^X,'b')
    
    s = [ord(c)-ord('0') for c in format(N,'b').zfill(31)]
    z = [ord(c)-ord('0') for c in format((1<<31)-1^X,'b')]
    
    s = s[-len(strBinN):]
    z = z[-len(strBinN):]
    
    
    
    dp = {}
    print(solve(0,0))
    
    