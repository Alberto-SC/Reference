#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int c = -1;
bool flag = true;
const int maxn = 200007;

vector<int> dist(maxn);
vector<int> vis(maxn);
vector<int> graph[maxn];
vector<int> token(maxn);
vector<int> red(maxn);
vector<int> valid(maxn);
void dfs(int u,int f, int d = 0){
    dist[u] = d;
    valid[u] = f;
    for(auto v:graph[u]){
        if(vis[v] || !red[v])continue ;
        vis[v] = 1;
        dfs(v,f,d+1);
        dist[u] =max(dist[u],d);
    }
}



signed main(){__
    int T = 1,n,m,u,v,p,b;
    while(T--){
        cin>>n>>m;
        cin>>p>>b;
        for(int i = 0;i<p;i++){
            cin>>u;
            u--;
            token[u] = 1;
        }
        for(int i = 0;i<b;i++){
            cin>>u;
            u--;
            red[u] =i;
            if(!vis[u])
                dfs(u);
        }
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool f = false;
        if(dist[0])f = true;
        for(auto v:graph[0]){
            if()
        }

        if(mn == 1e9){

        }
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
    }
    return 0;
}