#include <bits/stdc++.h>
using namespace std;
int first;
const int maxn = 200007;
vector<int> graph[maxn];
bool vis[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool flag;
void dfs(int u,int p = -1){
    if(graph[u].size()>2 || graph[u].size()<=1)flag =  false;
    int cont = 0;
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v])continue;
        cont++;
        dfs(v,u);
    }
    if(cont == 0 &&graph[u].size()== 2&& graph[u][0] != first && graph[u][1] != first)flag = false;
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            flag = true;
            first = i;
            dfs(i);
            ans+=flag;
        }
    }
    cout<<ans<<endl;
    return 0;
}