#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector<int> p;
vector<int> sz;

int root(int u){
    return u == p[u]?u:p[u]=root(p[u]);
}
int components = 0;

const int maxn = 200007;
set<pair<int,int>> graph[maxn];

void union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return ;
    if(sz[u]<sz[v])swap(u,v);
    for(auto x:graph[v]){
        graph[u].insert(x);
    }
    graph[v].clear();
    p[v] = u;
    components--;
    sz[u]+=sz[v];
}

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;

        for(int i = 0;i<n;i++)graph[i].clear();
        p.resize(n);
        iota(p.begin(),p.end(),0);
        sz.assign(n,1);
        
        vector<int> a(n);
        for(auto &c:a)cin>>c;

        while(m--){
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].insert({a[v],v});
            graph[v].insert({a[u],u});
        }

        queue<int> q;

        components = n;
        for(int i = 0;i<n;i++){
            if(a[i] == 0)q.push(i);
        }


        while(q.size()){
            auto u = q.front();
            q.pop();
            u = root(u);
            
            while(graph[u].size()&& root(u)== root(graph[u].begin()->second)){
                graph[u].erase(graph[u].begin());
            }
            
            if(!graph[u].size() || sz[u]<graph[u].begin()->first)continue;
            
            q.push(graph[u].begin()->second);
            union_by_size(u,graph[u].begin()->second);
        }
        
        if(components == 1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


