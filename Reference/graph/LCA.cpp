/**
 * Author: Alberto Silva
 * Date: 2020-02-20
 * License: CC0
 * Source: Folklore
 * Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected.
 * Time: $O(N \log N + Q log(n))$
 * Status: stress-tested
 */
const int maxn = 100007;
const int mxlog = 25;
vector<int> graph[maxn];
int parent[mxlog][maxn];
vector<int> deep(maxn);

int N;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void dfs(int u,int p = -1,int d = 0){
    deep[u] = d;
    parent[0][u] = p;
    for(auto v:graph[u]){
        if(v== p)continue;
        dfs(v,u,d+1);
    }
}

void build(){
    for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
    for(int i = 0;i<N;i++)deep[i]= -1;
    dfs(0);
    for(int i = 0;i<N;i++)
        if(deep[i]== -1)dfs(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<N;u++){
            if(parent[i-1   ][u]!= -1)
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
    }
}


// extra: minimum node in the path
const int mxlog = 20;
int P[mxlog][300000];
int MN[mxlog][300000];
vector<int> deep(300000);
vector<int> dist(300000);
int N;

void dfsLCA(int u,int p = -1,int d = 0){
    deep[u] = d;
    P[0][u] = p;
    MN[0][u] = dist[u];
    if(p!=-1)MN[0][u] =min(MN[0][u],dist[p]);

    for(auto v:graph[u]){
        if(v== p)continue;
        dfsLCA(v,u,d+1);
    }
}


int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    for(int i = mxlog-1;i>=0;i--){
        if(diff & (1<<i))
            v = parent[i][v];
    }
    if(u == v)return u; 

    for(int i = mxlog-1;i>=0;i--){
        if(parent[i][u]!= parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

void build(){
    for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)P[j][i] = -1;
    for(int i = 0;i<N;i++)deep[i]= -1;
    dfsLCA(0);
    for(int i = 0;i<N;i++)
        if(deep[i]== -1)dfsLCA(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<N;u++){
            if(P[i-1   ][u]!= -1){

                P[i][u] = P[i-1][P[i-1][u]];
                MN[i][u] = min(MN[i-1][u],MN[i-1][P[i-1][u]]);
            }
        }
    }
}

int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    int mn = min(dist[u],dist[v]);
    // cout<<"LCA: "<<u<<" "<<v<<" "<<mn<<endl;

    for(int i = mxlog-1;i>=0;i--){
        if(diff & (1<<i)){
            mn = min(mn,MN[i][v]);
            // cout<<mn<<endl;
            v = P[i][v];
        }
    }
    if(u == v)return mn; 

    for(int i = mxlog-1;i>=0;i--){
        if(P[i][u]!= P[i][v]){
            mn = min(mn,min(MN[i][u],MN[i][v]));
            // cout<<mn<<endl;
            u = P[i][u];
            v = P[i][v];
        }
    }
    mn = min(mn,min(MN[0][u],MN[0][v]));
    
    return mn;
}

// extra: OR with node values in the path u->v
const int LOG = 20;
const int maxn = 200007;
vector<int> graph[maxn];
vector<vector<int>> parent(maxn, vector<int>());
vector<vector<int>> orBin(maxn, vector<int>());
vector<int> depth(maxn);
vector<int> a(maxn);

void dfs(int u, int p, int d) {
    parent[u][0] = p;

    orBin[u][0] = a[u];
    if (p != -1) {
        orBin[u][0] |= a[p];
    }

    depth[u] = d;
    for (int v : graph[u]) {
        if (v == p) continue;
        
        dfs(v, u, d + 1);
    }
}

pair<int, int> lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];
    int OR = a[u] | a[v];

    for (int x = LOG - 1; x >= 0; --x) {
        if ((diff >> x) & 1) {
            OR |= orBin[u][x];
            u = parent[u][x];
        }
    }

    if (u == v) {
        return {OR, u};
    }

    for (int x = LOG - 1; x >= 0; --x) {
        if (parent[u][x] != parent[v][x]) {
            OR |= orBin[u][x];
            OR |= orBin[v][x];
            u = parent[u][x];
            v = parent[v][x];
        }
    }

    OR |= orBin[u][0] | orBin[v][0];
    return {OR, parent[u][0]};
}

int dist(int u, int v, int LCA) {
    return depth[u] + depth[v] - 2 * depth[LCA];
}

int getParent(int u, int x) {
    for (int i = LOG - 1; i >= 0; --i) {
        if ((x >> i) & 1) {
            u = parent[u][i];
        }
    }
    return u;
}

int getNode(int u, int v, int LCA, int x) {
    if (dist(u, LCA, LCA) >= x) {
        return getParent(u, x);
    } else {
        return getParent(v, dist(v, LCA, LCA) - (x - dist(u, LCA, LCA)));
    }
}

// Usage:
// Cleaning
for (int i = 0; i < n; ++i) {
    graph[i].clear();
    parent[i] = vector<int>(LOG, -1);
    orBin[i] = vector<int>(LOG, 0);
}

dfs(0, -1, 0);

for (int u = 1; u < LOG; ++u) {
    for (int i = 0; i < n; ++i) {
        if (parent[i][u - 1] == -1)continue;
        parent[i][u] = parent[parent[i][u - 1]][u - 1];
        orBin[i][u] = orBin[i][u - 1] | orBin[parent[i][u - 1]][u - 1];
    }
}
