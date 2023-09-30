#pragma comment(linker, "/STACK:268435456");
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
set<int> graph[maxn];
set<int> graph2[maxn];
vector<int> low(maxn),d(maxn),label(maxn),parent(maxn);
vector<bool> bridge(maxn),vis(maxn);
vector<int> color(maxn,-1);
vector<int> value(maxn);

int idx;
void dfs(int u,int p = -1){
    // cout<<u<<" "<<p<<endl;
    d[u] = idx++;
    low[u] = d[u];
    vis[u] = true;
    parent[u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        // cout<<v<<endl;
        if(!vis[v]){
            dfs(v,u);
            if(low[v]>d[u]) bridge[v] = true;
        }
        low[u] = min(low[u],low[v]);
    }    
}

bool bipartite = true;
void dfs_label(int u,int p = -1){
    if(p ==-1)color[u] = 0;
    else color[u] = 1-color[p];

    label[u] = idx;
    for(auto v : graph[u]){
        if(v == p)continue;

        if(color[v] == color[u])
            bipartite = false;
        if(color[v] == -1)
            dfs_label(v,u);
    }
}
 

const int mxlog = 20;
int P[mxlog][300000];
int MN[mxlog][300000];
vector<int> deep(300000);
vector<int> dist(300000);
int N;

void dfsLCA(int u,int p = -1,int d = 0){
    deep[u] = d;
    P[0][u] = p;
    MN[0][u] = dist[u];
    if(p!=-1)MN[0][u] =min(MN[0][u],dist[p]);

    for(auto v:graph[u]){
        if(v== p)continue;
        dfsLCA(v,u,d+1);
    }
}

void build(){
    for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)P[j][i] = -1;
    for(int i = 0;i<N;i++)deep[i]= -1;
    dfsLCA(0);
    for(int i = 0;i<N;i++)
        if(deep[i]== -1)dfsLCA(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<N;u++){
            if(P[i-1   ][u]!= -1){

                P[i][u] = P[i-1][P[i-1][u]];
                MN[i][u] = min(MN[i-1][u],MN[i-1][P[i-1][u]]);
            }
        }
    }
}

int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    int mn = min(dist[u],dist[v]);
    // cout<<"LCA: "<<u<<" "<<v<<" "<<mn<<endl;

    for(int i = mxlog-1;i>=0;i--){
        if(diff & (1<<i)){
            mn = min(mn,MN[i][v]);
            // cout<<mn<<endl;
            v = P[i][v];
        }
    }
    if(u == v)return mn; 

    for(int i = mxlog-1;i>=0;i--){
        if(P[i][u]!= P[i][v]){
            mn = min(mn,min(MN[i][u],MN[i][v]));
            // cout<<mn<<endl;
            u = P[i][u];
            v = P[i][v];
        }
    }
    mn = min(mn,min(MN[0][u],MN[0][v]));
    
    return mn;
}

signed main(){
	int t= 1,n,u,v,m,Q;
    cin>>t;
    int id = 1;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)graph[i].clear(),bridge[i] = false,vis[i] = false,dist[i] = 1e9+7,color[i] = -1;
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        idx = 0;
        dfs(0);

        vector<pair<int,int>> bridges;
        for(int i = 0;i<n;i++){
            vis[i] = false;
            if(bridge[i]){
                // cout<<"I: "<<i<<" "<<parent[i]<<endl;
                graph[i].erase(parent[i]);
                graph[parent[i]].erase(i);
                if(i)bridges.push_back({i,parent[i]});
            }
        }
        idx = 0;

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(color[i] ==-1){
                bipartite = true;
                dfs_label(i);
                if(!bipartite){
                    q.push(idx);
                    dist[idx] = 0;
                }
                idx++;
            }
        }
        for(int i = 0;i<n;i++)
            graph[i].clear(),vis[i] = false;
        for(auto v:bridges){
            int a = label[v.first],b = label[v.second];
            graph[a].insert(b);
            graph[b].insert(a);
        }


        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v:graph[u]){
                if(dist[v]>dist[u]+1){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }

  
        N = idx;
        build();

        cin>>Q;
        int sum = 0;

        while(Q--){
            cin>>u>>v;
            u--,v--;
            int SU = label[u],SV = label[v];
            int mn = lca(SU,SV);
            if(mn == 1e9+7)mn = -1;
            sum+=mn;
        }

        cout<<"Case #"<<id<<": "<<sum<<endl;
        id++;
    }  
    return 0;
}  