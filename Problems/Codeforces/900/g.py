import sys
input = sys.stdin.readline

def solve():
  n = int(input())
  a = list(map(int,input().split()))

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

  def getParent(u,x):
    for i in range(LOG-1,-1,-1):
      if (x>>i)&1:
        u = parent[u][i]
    return u

  def getNode(u,v,LCA,x):
    if dist(u,LCA,LCA) >= x:
      return getParent(u,x)
    else:
      return getParent(v,dist(v,LCA,LCA)-(x-dist(u,LCA,LCA)))


  Q = int(input())

  for i in range(Q):
    u,v = map(int,input().split())
    u-=1
    v-=1
    if depth[u] < depth[v]: u,v = v,u

    OR,LCA = lca(u,v)
    LEN = dist(u,v,LCA)

    last = 0
    ans = format(OR,'b').count('1')
    for bits in range(1,format(OR,'b').count('1')+1):
      L = -1
      R = LEN

      while L+1<R:
        mid = (L+R)//2
        NODE = getNode(u,v,LCA,mid)
        OR,LCA2 = lca(u,NODE)

        if format(OR,'b').count('1') >= bits: 
          R = mid
        else:
          L = mid

      NODE = getNode(u,v,LCA,R)
      ans = max(ans,format(lca(u,NODE)[0],'b').count('1')+ format(lca(NODE,v)[0],'b').count('1'))

    print(ans,end =' ')


for _ in range(int(input())):
  solve()
  print("")