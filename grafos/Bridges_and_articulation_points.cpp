#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007; 
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int bridges;
vector<int> dp(maxn);
vector<int> lvl(maxn);
void dfs(int u){
    dp[u] = 0;
    for(auto v:graph[u]){
        if(lvl[v] == 0){
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
    if(lvl[u]>1 && dp[u] ==0)bridges++;
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        add_edge(u,v);
    }
    lvl[1] = 1;
    dfs(1);
    // for(int i = 1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<lvl[i]<<" ";
    // cout<<endl;
    cout<<bridges<<endl;
    return 0;
}