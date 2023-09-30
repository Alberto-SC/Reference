#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli maxn = 200007;
set<lli> graph[maxn];
set<lli> graph2[maxn];
vector<lli> low(maxn),d(maxn),label(maxn),bridge(maxn),vis(maxn),parent(maxn),sz(maxn);

lli idx;
void dfs(lli u,lli p = -1){
    d[u] =idx++;
    low[u] = d[u];
    vis[u] = true;
    sz[u]= 1;
    parent[u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v]){
            dfs(v,u);
            sz[u]+=sz[v];
            if(low[v]>d[u]) bridge[v] = true;
        }
        low[u] = min(low[u],low[v]);
    }    
}
void dfs_label(lli u){
    vis[u] = 1;
    label[u] = idx;
    for(auto v : graph[u])
        if(!vis[v])
            dfs_label(v);
}
 
int main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(lli i = 0;i<n;i++)graph[i].clear(),graph2[i].clear(),bridge[i] = false,vis[i] = false;
        for(lli i = 0;i<n;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
            graph[v].insert(u);
            graph2[u].insert(v);
            graph2[v].insert(u);
        }
        dfs(0);
        lli root;
        set<lli> cycle;
        vector<pair<lli,lli>> bridges;
        for(lli i = 0;i<n;i++){
            vis[i] = false;
            if(bridge[i]){
                graph[i].erase(parent[i]);
                graph[parent[i]].erase(i);
                if(i)bridges.push_back({i,parent[i]});
            }
            else{
                if(i){
                    cycle.insert(parent[i]);
                    cycle.insert(i);
                    root = i;
                }
            }
        }
        idx = 0;
        for(lli i = 0;i<n;i++){
            if(!vis[i]){
                dfs_label(i);
                idx++;
            }
        }
        lli y = cycle.size();
        lli x = n-cycle.size();
        lli ans = (y*x*2)-x;
        ans += (y*(y-1));
        for(lli i = 0;i<n;i++)
            graph[i].clear(),vis[i] = false;
        for(auto v:bridges){
            lli a = label[v.first],b = label[v.second];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        dfs(label[root]);
        lli total = 0;
        for(auto c:graph[label[root]]){
            if(sz[c]>1){
                ans+= (sz[c]* (sz[c]-1))/2;
            }
            total+=sz[c];
        }
        lli m = 0;
        for(auto c:graph[label[root]]){
            m+= sz[c]*(total-sz[c])*2;
        }
        m/=2;
        ans+=m;
        for(auto c:cycle){
            lli cont = 0,childs= 0,cont2 = 0;
            for(auto d:graph2[c]){
                if(label[d]!= label[root]){
                    cont+=sz[label[d]];
                    if(sz[label[d]]>1)
                        cont2+=(sz[label[d]]* (sz[label[d]]-1))/2;
                    childs++;
                }
            }
            if(childs>1)
                ans-=((cont*(cont-1))/2)-cont2; 
        }
        cout<<ans<<endl;
    }  
    return 0;
}  


