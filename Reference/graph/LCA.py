
"""
 * Author: Alberto Silva
 * Date: 2023-06-20
 * License: CC0
 * Source: Folklore
 * Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected this version also calc the the min/max of the path from $u$ to $v$.
 * Time: $O(N \log N + Q)$
 * Status: stress-tested

""" 


LOG = 10    
parent = [[-1]*LOG for _ in range(n)]
mxBin = [[0]*LOG for _ in range(n)]
depth = [0]*n

def dfs(u,p = -1,mx = 0,d = 0):
    parent[u][0] = p
    mxBin[u][0] = mx
    depth[u] = d
    for v,w,id in graph[u]:
        if v == p: continue
        dfs(v,u,w,d+1)

dfs(0)
for u in range(1,LOG):
    for i in range(n):
        if parent[i][u-1]==-1: continue 
        parent[i][u] = parent[parent[i][u-1]][u-1]
        mxBin[i][u] = max(mxBin[i][u-1],mxBin[parent[i][u-1]][u-1])



def lca(u,v):
    if depth[u]<depth[v]: u,v = (v,u)

    diff = depth[u]-depth[v]
    mx = 0 

    for x in range(LOG-1,-1,-1):
        if (diff>>x) &1: 
            mx = max(mx,mxBin[u][x])
            u = parent[u][x]

    if u == v: 
        return (mx,u)

    for x in range(LOG-1,-1,-1):
        if parent[u][x] != parent[v][x]:
            mx = max(mx,mxBin[u][x])
            mx = max(mx,mxBin[v][x])
            u = parent[u][x]
            v = parent[v][x]


    mx = max(mx,mxBin[u][0])
    mx = max(mx,mxBin[v][0])

    return (mx,parent[u][0])


# OR version and some util functions 
graph = [[] for i in range(n)]
for i in range(n-1):
u,v = map(int,input().split())
u-=1
v-=1
graph[u].append(v)
graph[v].append(u)

LOG = 20    
parent = [[-1]*LOG for _ in range(n)]
orBin = [[0]*LOG for _ in range(n)]
depth = [0]*n

def dfs(s):
    stack = [(s,-1,0)]
    while stack:
    u,p,d = stack.pop()
    parent[u][0] = p
    
    orBin[u][0] = a[u]
    if p !=-1:
        orBin[u][0] |= a[p]

    depth[u] = d
    for v in graph[u]:
        if v == p: continue
        stack.append((v,u,d+1))

dfs(0)
for u in range(1,LOG):
    for i in range(n):
        if parent[i][u-1]==-1: continue 
        parent[i][u] = parent[parent[i][u-1]][u-1]
        orBin[i][u] = orBin[i][u-1] | orBin[parent[i][u-1]][u-1]



def lca(u,v):
    if depth[u]<depth[v]: u,v = (v,u)

    diff = depth[u]-depth[v]
    OR = a[u]|a[v] 

    for x in range(LOG-1,-1,-1):
        if (diff>>x) &1: 
            OR |= orBin[u][x]
            u = parent[u][x]

    if u == v: 
        return (OR,u)

    for x in range(LOG-1,-1,-1):
        if parent[u][x] != parent[v][x]:
            OR |= mxBin[u][x]
            OR |= mxBin[v][x]
            u = parent[u][x]
            v = parent[v][x]


    OR |= orBin[u][0] | orBin[v][0]
    return (OR,parent[u][0])

def dist(u,v,LCA): 
return depth[u] + depth[v] - 2*depth[LCA]

# get parent at  x distance from u
def getParent(u,x):
for i in range(LOG-1,-1,-1):
    if (x>>i)&1:
    u = parent[u][i]
return u

# get node at x distance from u in the path from u to v
def getNode(u,v,LCA,x):
if dist(u,LCA,LCA) >= x:
    return getParent(u,x)
else:
    return getParent(v,dist(v,LCA,LCA)-(x-dist(u,LCA,LCA)))

