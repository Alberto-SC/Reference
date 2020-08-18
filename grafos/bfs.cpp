int q[maxn];
int topQ;
void bfs(int g,int n){
    for (int i = 0; i<n;i++)
        dist[i] = INF;
    topQ = 0;
    for (int x : root[g]) {
        dist[x] = 0;
        q[topQ++] = x;
    }
    for (int i = 0; i < topQ; i++) {
        int u = q[i];
        for (int v : graph[u]) {
            if (dist[v] <= dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            q[topQ++] = v;
        }
    }
    for(int i = 0;i<n;i++)
        ans[i].push_back(dist[i]);
}
// FInd the minimun distance any node to any node of a set of special nodes 