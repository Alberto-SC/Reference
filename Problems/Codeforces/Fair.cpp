#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> types(maxn);
vector<int> root[107];
vector<int> graph[maxn];
vector<int> dist(maxn);
vector<int> ans[maxn];

const int INF = 1000000000;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

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

int main(){
    int n,m,k,s,u,v;
    cin>>n>>m>>k>>s;
    for(int i = 0;i<n;i++){
        cin>>types[i];
        root[types[i]].push_back(i); 
    }
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    for(int i = 1;i<=k;i++)
        bfs(i,n);
    for(int i = 0;i<n;i++){
        sort(ans[i].begin(),ans[i].end());
        int res = 0;
        for(int j = 0;j<s;j++)res+= ans[i][j];
        cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}