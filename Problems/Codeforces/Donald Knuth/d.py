import sys
input = sys.stdin.readline
from collections import defaultdict
import heapq

n,l,t = map(int,input().split())
graph = [[] for _ in range((n*l)+7)]

id = 0 
mp = defaultdict(list)

idStart = 0
for i in range(l):
  arr = list(map(int,input().split()))


  k = arr[0]
  last = -1
  arr = arr[1:]

  for x in arr:
    if i == 0 and x == 1: idStart = id
    if last !=-1:
      graph[last].append(id)
      graph[id].append(last)
    mp[x].append(id)
    last = id 
    id+=1 


for i in mp.keys():
  for a in range(len(mp[i])):
    for b in range(len(mp[i])):
        if(a !=b):
          graph[mp[i][a]].append(mp[i][b])
          graph[mp[i][b]].append(mp[i][a])



pq = [idStart]
dist = [10**9]*id
dist[idStart] = 0

while pq : 
  u = heapq.heappop(pq)

  for v in graph[u]:
    if dist[v] > dist[u]+1:
      dist[v] = dist[u]+1
      heapq.heappush(pq,v)


ans = [10**9]*(n+1)
for i in mp.keys():
  ans[i] = min([dist[x] for x in mp[i]])

print(*([x*t if x != 10**9 else -1 for x in ans[1:]]))


  
  

