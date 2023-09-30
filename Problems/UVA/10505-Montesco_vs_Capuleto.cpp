#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

bool bipartite = true;
int sz[2];
const int maxn = 207;
vector<int> color(maxn,-1);
vector<int> graph[maxn];
void dfs(int u,int p = -1){
    if(p ==-1){
        color[u] = 0;
        sz[0]++;
    }
    else
        color[u] = color[p]^1,sz[color[u]]++;
    
    for(auto v:graph[u]){
        if(v == p)continue;
        if(color[v] ==-1)dfs(v,u);
        else if(color[v]==color[u])bipartite = false;
    }
}

signed main(){__
    int t,p,u,v;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
            graph[i].clear();
        for(int i = 0;i<n;i++){
            cin>>p;
            for(int j = 0;j<p;j++){
                cin>>v;
                v--;
                if(v<n){
                    graph[i].push_back(v);
                    graph[v].push_back(i);
                }
            }
        }
    
        color.assign(n,-1);
        int ans = 0; 
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                bipartite = true;
                sz[0] = 0;
                sz[1] = 0;
                dfs(i);
                if(bipartite)
                    ans+=max(sz[0],sz[1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

