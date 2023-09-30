with open("in_j1") as lectura:
    data = lectura.read()

graph = []
DP = []
b = []
last = 0
def dfs(node):
    if DP[node]!= -1:
        return DP[node]
    if node ==last:
        DP[node] = 1
        return DP[node]
    ans = 0
    for neighbour in graph[node]:
        dfs(neighbour)
        ans = ans+DP[neighbour]
    DP[node] = ans
    return DP[node]

jolt = [0]+[int(i) for i in data.split("\n")]
jolt.sort()
for i in range(1000):
    DP.append(-1)
    graph.append([])
    b.append(0)

last = jolt[len(jolt)-1]
for i in jolt:
    b[i] = 1
for i in jolt:
    print(i)
    if(b[i+1] == 1):
        graph[i].append(i+1)
    if(b[i+2] == 1):
        graph[i].append(i+2)
    if(b[i+3] == 1):
        graph[i].append(i+3)

print(dfs(0))

