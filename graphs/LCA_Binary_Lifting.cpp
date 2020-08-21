#include <bits/stdc++.h>
using namespace std;
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
    for(int i = 0;i<N;i++)
        if(deep[i]== -1)dfs(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<N;u++){
            if(parent[i-1   ][u]!= -1)
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
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
void init(){
    for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
    for(int i = 0;i<N;i++)deep[i]= -1;
    dfs(0);
    build();
}
int main(){
    int t,n,u,m,q,v;
    cin>>t;
    int cont = 1;
    while(t--){
        cin>>n;
        N = n;
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i= 0;i<n;i++){
            cin>>m;
            for(int j = 0;j<m;j++){
                cin>>u;
                u--;
                graph[i].push_back(u);
            }
        }
        init();
        cin>>q;
        cout<<"Case "<<cont<<":"<<endl;
        for(int i = 0;i<q;i++){
            cin>>u>>v;
            u--,v--;
            cout<<lca(u,v)+1<<endl;
        }
        cont++;
    }
    return 0;
} 