#include <bits/stdc++.h>
using namespace std;
const int maxn = 300007;
vector<int> graph[maxn];

void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> dp(maxn);
vector<int> parent(maxn);
vector<int> lvl(maxn);

int bridges;
void dfs(int u){
    dp[u] = 0;
    for(auto v:graph[u]){
        if(lvl[v] ==0){
            parent[v] = u;
            lvl[v] = lvl[u]+1;
            dfs(v);
            dp[u] += dp[v];
        }
        else if(lvl[v]<lvl[u])
            dp[u]++;
        else if(lvl[v]>lvl[u])
            dp[u]--;
    }
    dp[u]--;
    if(lvl[u] >1&& dp[u] == 0)
        bridges++;
}



int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        edges.push_back({u,v});
        add_edge(u,v);
    }
    lvl[0] = 1;
    dfs(0);
    if(bridges)return cout<<0<<endl,0;
    for(int i = 0;i<m ;i++){
        if(parent[edges[i].second] == edges[i].first)cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
        else if(parent[edges[i].first]== edges[i].second)cout<<edges[i].second+1<<" "<<edges[i].first+1<<endl;
        else {
            if(lvl[edges[i].second]>lvl[edges[i].first])
                swap(edges[i].first,edges[i].second);
            cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
        }
    }
    return 0;
}