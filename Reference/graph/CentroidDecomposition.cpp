/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2020-01-12
 * License: CC0
 * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
 * Description: Decomposes a tree into centroids and create a new tree with the centroids
 * Time: O(n \log n)
 * Status: stress-tested against old HLD
 */
const int maxn = 100005;
vector<int> graph[maxn];
vector<int> parent(maxn,-1);
vector<int> depth(maxn,-1);
vector<int> best(maxn,1e16);
int P[maxn][25];
bitset<maxn> cent;
int sz[maxn];

void dfs (int u, int p = -1,int d = 0) {
    sz[u] = 1;
    P[u][0] = p;
    depth[u] = d;
    for (int v : graph[u]){   
        if(v ==p)continue;
        dfs(v,u,d+1);
        sz[u] += sz[v];
    }
}

void build(int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<25;j++)
            P[i][j] = -1;
    dfs(0);
    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(P[u][i-1]!=-1)
                P[u][i] = P[P[u][i-1]][i-1];
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--){
        if((diff>>i)&1){
            u = P[u][i];
        }
    }
    if(u==v)return u;
    for(int i= 24;i>=0;i--){
        if(P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}


int descomp (int u) {
    int tam = 1;
    for (int v : graph[u])
        if (!cent[v]) 
            tam += sz[v];

    while (1) {
        int idx = -1;
        for (int v : graph[u])
            if (!cent[v] && 2 * sz[v] > tam)
                idx = v;
        if (idx == -1)break;<
        sz[u] = tam - sz[idx];
        u = idx;
    }

    cent[u] = 1;
    
	for (int v : graph[u])
        if (!cent[v])
            parent[descomp(v)] = u;

    return u;
}
