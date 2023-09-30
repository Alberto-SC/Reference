#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
int last = 0;

void dfs(int u){
    last = u;
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
    }
}

void dfs2(int u,int p = -1){
    if(p!=-1)
        cout<<u+1<<" "<<p+1<<endl;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs2(v,u);
    }
}
signed main(){__
	int t= 1,n,m,x,y,z;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i= 0;i<n;i++)
            vis[i] = false,graph[i].clear();

        for(int i = 0;i<m;i++){
            cin>>x>>y>>z;
            x--,y--,z--;
            graph[x].push_back(z);
            graph[z].push_back(x);
        }
        vector<int> components;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                components.push_back(last);
            }
        }

        for(int i = 0;i<components.size()-1;i++){
            graph[components[i]].push_back(components[i+1]);
            graph[components[i+1]].push_back(components[i]);
        }
        dfs2(0);
    }
    return 0;
}  
