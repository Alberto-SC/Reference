#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 10007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
int sz = 0;
void dfs(int u){
    sz++;
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
    }
}

signed main(){__
	int t= 1,n,m,u,v;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int a =0,b = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                sz = 0;
                dfs(i);
                if(sz>1)a++;
                else b++;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}  
