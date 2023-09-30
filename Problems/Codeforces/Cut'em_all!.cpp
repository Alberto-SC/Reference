#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> sz(maxn,1);
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int dfs(int u,int p = -1){
    if(graph[u].size()==1 && u != 0)return sz[u];
    for(auto v:graph[u]){
        if(v == p)continue;
        sz[u]+=dfs(v,u);
    }
    return sz[u];
}
int cont = 0;
int dfs2(int u,int n,int p = -1){
    for(auto v:graph[u]){
        if(v == p)continue;
        if(n%2 == 0 && sz[v]%2 == 0)dfs2(v,sz[v],u),n-=sz[v],cont++;
        else dfs2(v,n,u);
    }
}

int main(){
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    if(n&1)return cout<<-1<<endl,0;
    dfs(0);
    dfs2(0,sz[0]);
    cout<<cont<<endl;
    return 0;
}