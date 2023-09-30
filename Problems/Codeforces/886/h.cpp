#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> vis(maxn);
vector<pair<int,int>> graph[maxn];
vector<int> pos(maxn);

void dfs(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v.first]){
            pos[v.first] = pos[u]+v.second;
            dfs(v.first);
        }
    }
}
struct S{
    int u,v,d;
};

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)graph[i].clear(),vis[i] = 0,pos[i] = 0;
        vector<S> C;
        for(int i = 0;i<m;i++){
            int u,v,d;
            cin>>u>>v>>d;
            u--,v--;
            graph[u].push_back({v,d});
            graph[v].push_back({u,-d});
            C.push_back({u,v,d});
        }

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                pos[i] = 0;
                dfs(i);
            }
        }

        bool flag = true;
        for(int i = 0;i<m;i++){
            int u = C[i].u;
            int v = C[i].v;
            int d = C[i].d;
            if(pos[u]+d != pos[v]){
                flag = false;
                break;
            }
        }

        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}