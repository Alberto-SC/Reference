import math
val = []
graph = []
def dfs(u,p):
    c = 0    
    for v in graph[u]:
        if v==p:
            continue
        dfs(v,u)
        c = c+1
    childrens =[]
    for v in graph[u]:
        if v==p:
            continue
        childrens.append(val[v])
    childrens.sort(reverse=True)
    for i in range(1,c+1):
        x = val[u]
        val[u] = x+(childrens[i-1]*i)

mod = 1e9+7
t=int(input())
while t:
    n,x=input().split()
    n=int(n)
    x=int(x)
    val = []
    graph = []
    for i in range(0,n):
        graph.append([]),val.append(x) 
    
    for i in range(0,n-1):
        a,b=input().split()
        graph[int(a)-1].append(int(b)-1)
        graph[int(b)-1].append(int(a)-1)
    dfs(0,-1)
    print(math.floor(val[0]%mod))
    t-=1