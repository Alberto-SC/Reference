#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> sz(maxn);
vector<vector<int>> paths;
vector<int> graph[maxn];

vector<int> depth(maxn);
void dfsSz(int u,int d = 0){
    depth[u] = d;
    sz[u] = 1;
    for(auto v:graph[u]){
        dfsSz(v,d+1);
        sz[u]+=sz[v];
    }
}

int idx = 0;
vector<bool> vis(maxn);
void dfs2(int u){
    vis[u] = true;
    if(paths.size()== idx)paths.push_back({});
    paths[idx].push_back(u);
    int heavy = -1,mx = 0;
    for(auto v:graph[u]){
        if(sz[v]>mx){
            mx = sz[v];
            heavy = v;
        }
    }
    if(heavy!=-1)
        dfs2(heavy);
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int root = 0;
        for(int i =0 ;i<n;i++){
            vis[i] = false;
            graph[i].clear();
        }
        paths.clear();
        for(int i = 0;i<n;i++){
            int p;
            cin>>p;
            p--;
            if(p == i)root = i;
            else graph[p].push_back(i);
        }
        dfsSz(root);
        idx = 0;
        vector<int> nodes(n);
        iota(nodes.begin(),nodes.end(),0);
        sort(nodes.begin(),nodes.end(),[&](int a,int b){
            return depth[a]<depth[b];
        });
        for(int i = 0;i<n;i++){
            if(!vis[nodes[i]]){
                dfs2(nodes[i]);
                idx++;
            }
        }
        cout<<paths.size()<<endl;
        for(auto c:paths){
            cout<<c.size()<<endl;
            for(auto d:c)cout<<d+1<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}