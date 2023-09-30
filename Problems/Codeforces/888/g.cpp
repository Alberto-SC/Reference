#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
 
vector<int> p(maxn);
vector<int> sz(maxn);

int root(int u){
    return u == p[u]? u: p[u] = root(p[u]);
}

void union_by_sz(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(sz[u]<sz[v])swap(u,v);
    p[v] = u;
    sz[u]+=sz[v];
}

struct E{
    int u,v,w;
};

struct Q{
    int id,u,v,e;
};
signed main(){__
	int T= 1,n,u,v,m,q,e;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<E> edges;
        for(int i = 0;i<n;i++)p[i] = i,sz[i] = 1;

        vector<int> h(n);
        for(auto &c:h)cin>>c;

        for(int i= 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            edges.push_back({u,v,max(h[u],h[v])});
        }

        sort(edges.begin(),edges.end(),[&](E a,E b){
            return a.w<b.w;
        });


        cin>>q;
        vector<Q> queries;
        for(int i = 0;i<q;i++){
            cin>>u>>v>>e;
            u--,v--;
            queries.push_back({i,u,v,h[u]+e});
        }

        sort(queries.begin(),queries.end(),[&](Q a,Q b){
            return a.e<b.e;
        });


        int id = 0;
        vector<string> ans(q,"NO");
        for(int i = 0;i<q;i++){
            int a = queries[i].u;
            int b = queries[i].v;
            int idx = queries[i].id;
            int e = queries[i].e;
            while(id<edges.size()){
                int u = edges[id].u;
                int v = edges[id].v;
                int w = edges[id].w;
                if(w>e)break;
                union_by_sz(u,v);
                id++;
            }

            if(root(a) == root(b))ans[idx] = "YES";
        }

        for(auto c:ans)cout<<c<<endl;
        cout<<endl;
    }  
    return 0;
}  


