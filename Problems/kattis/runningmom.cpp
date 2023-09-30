#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

bool bipartite = true;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> vis(maxn);
void dfs(int u,int p = -1){
    for(auto v:graph[u]){
        if()
        if(color[v]==-1)dfs(v,u);   
        else if(color[v]==color[u])bipartite = false;
    }
}

signed main(){__

}