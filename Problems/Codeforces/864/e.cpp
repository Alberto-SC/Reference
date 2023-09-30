#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;

struct S{
    int id,sz;
    bool operator<(const S &other) const{
        if(sz == other.sz)return id<other.id;
        return sz > other.sz;
    }
};

vector<int> graph[maxn];
vector<int> a(maxn);
vector<int> sz(maxn);
vector<int> importance(maxn);
vector<set<S>> heavy(maxn);
vector<int> parent(maxn);

void dfs(int u,int p = -1){
    sz[u] = 1;
    importance[u] =a[u];
    parent[u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u);
        importance[u]+=importance[v];
        sz[u]+=sz[v];
        heavy[u].insert({v,sz[v]});
    }
}



signed main(){__
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }

        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0);

        while(m--){
            int t,x;
            cin>>t>>x;
            x--;
            if(t ==1){
                cout<<importance[x]<<endl;
            }
            else{
                if(heavy[x].size()==0){
                    continue;
                }

                auto best = *heavy[x].begin();
                S last = {x,sz[x]};
                sz[x]-=sz[best.id];
                sz[best.id]+=sz[x];

                importance[x]-=importance[best.id];
                importance[best.id]+=importance[x];


                S current = {x,sz[x]};
                heavy[parent[x]].erase(last);
                heavy[x].erase(best);

                heavy[parent[x]].insert({best.id,sz[best.id]});
                heavy[best.id].insert(current);

                parent[best.id] = parent[x];
                parent[x] = best.id;
            }
        }
    }
    return 0;
}