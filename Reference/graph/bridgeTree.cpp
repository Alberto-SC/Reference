/**
 * Author: Alberto silva
 * Date: 2019-04-26
 * License: CC0
 * Description: Get biconnected components and compress and compresse in a node each 
 * component, form a graph with the new compressed nodes
*/

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
        for(lli i = 0;i<n;i++)graph[i].clear(),bridge[i] = false,vis[i] = false;
        for(lli i = 0;i<n;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        dfs(0);

        vector<pair<lli,lli>> bridges;
        for(lli i = 0;i<n;i++){
            vis[i] = false;
            if(bridge[i]){
                graph[i].erase(parent[i]);
                graph[parent[i]].erase(i);
                if(i)bridges.push_back({i,parent[i]});
            }
        }
        idx = 0;
        for(lli i = 0;i<n;i++){
            if(!vis[i]){
                dfs_label(i);
                idx++;
            }
        }


        for(lli i = 0;i<n;i++)
            graph[i].clear(),vis[i] = false;
        for(auto v:bridges){
            lli a = label[v.first],b = label[v.second];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        
        // Now graph has the bridge tree
        // use label to know the component of each node
        // use another vector if you want to keep the original graph
    }  
    return 0;
}  


