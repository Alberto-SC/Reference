import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10**6)
S,T = (-1,-1)
graph = []
def dfs(u,p = -1):
  vis[u] = True
  for v in graph[u]:
    if v == p:continue 
    if vis[v]: 
      global S,T
      S = v 
      T = u
    else :
      dfs(v,u)

for _ in range(int(input())):
  n,a,b = map(int,input().split())
  a-=1
  b-=1
  graph = [[] for _ in range(n)]
  
  for i in range(n):
    u,v = map(int,input().split())
    u-=1
    v-=1
    graph[u].append(v)
    graph[v].append(u)

  S = -1 
  T = -1
  vis = [False]*n


  dfs(0)

  q = deque()
  q.append(S)

  parent = [-1]*n
  vis = [False]*n
  vis[S] = True

  while q: 
    u = q.popleft()
    if u == T: 
      break
    for v in graph[u]:
      if u == S and v == T:continue
      if vis[v]:continue
      vis[v] = True
      parent[v] = u  
      q.append(v)


  cycle = []
  while T!=S and T!=-1: 
    cycle.append(T)
    T = parent[T]
  cycle.append(S)

  q = deque()
  distA = [10**9]*n
  q.append(a)
  distA[a] = 0

  while q: 
    u = q.popleft()
    for v in graph[u]:
      if distA[v] > distA[u] + 1:
        distA[v] = distA[u]+1
        q.append(v)
  
  q = deque()
  distB = [10**9]*n
  q.append(b)
  distB[b] = 0

  while q: 
    u = q.popleft()
    for v in graph[u]:
      if distB[v] > distB[u] + 1:
        distB[v] = distB[u]+1
        q.append(v)
  
  flag = False


  for c in cycle: 
    if distB[c] < distA[c]:
      flag = True

  if b in cycle and a!= b:
    flag = True

  if flag:
    print('YES')
  else: 
    print('NO')
    
