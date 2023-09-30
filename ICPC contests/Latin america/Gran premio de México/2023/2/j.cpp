#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
set<int> graph[maxn];
vector<int> low(maxn),d(maxn),label(maxn),bridge(maxn),vis(maxn),parent(maxn),C(maxn),sz(maxn);

int idx;
void dfs(int u,int p = -1){
  d[u] =idx++;
  low[u] = d[u];
  vis[u] = true;
  parent[u] = p;
  for(auto v:graph[u]){
    if(v == p)continue;
    if(!vis[v]){
      dfs(v,u);
      if(low[v]>d[u]) bridge[v] = true;
    }
    low[u] = min(low[u],low[v]);
  }    
}
int SZ = 0;
void dfs_label(int u){
  vis[u] = 1;
  SZ++;
  label[u] = idx;
  for(auto v : graph[u])
    if(!vis[v])
      dfs_label(v);
}
 
vector<int> acSz(maxn);

int P[maxn][25];

void dfs2(int u,int ac,int p =-1,int D = 0){
  vis[u] = 1;
  d[u] = D;
  P[u][0] = p;
  ac+=sz[u];
  acSz[u] = ac;
  for(auto v:graph[u]){
    if(!vis[v]){
      dfs2(v,ac,u,D+1);
    }
  }
  ac-=sz[u];
}

void build(int n){
  for(int i = 0;i<n;i++)for(int j = 0;j<25;j++)P[i][j] = -1;
  dfs2(0,0);

  for(int j = 1;j<25;j++){
    for(int i = 0;i<n;i++){
      if(P[i][j-1]!=-1)
        P[i][j] = P[P[i][j-1]][j-1];
    }
  }
}

int lca(int u,int v){
  if(d[u]<d[v])swap(u,v);
  for(int i = 24;i>=0;i--){
    if(d[u]-(1<<i)>=d[v])
      u = P[u][i];
  }
  if(u==v)return u;
  for(int i = 24;i>=0;i--){
    if(P[u][i]!=-1 && P[u][i]!=P[v][i]){
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}

int getLen(int u,int v){
  int LCA = lca(u,v);
  return (d[u]+d[v]-(2*d[LCA]))+1;
}

int getSize(int u,int v){
  int LCA = lca(u,v);
  return acSz[u]+acSz[v]-2*acSz[LCA]+sz[LCA];
}

signed main(){__
	int t= 1,n,m,q,u,v;
  cin>>n>>m>>q;
  for(int i = 0;i<m;i++){
    cin>>u>>v;
    u--,v--;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  dfs(0);
  int root = n;
  vector<pair<int,int>> bridges;
  for(int i = 0;i<n;i++){
    vis[i] = false;
    if(bridge[i]){
      graph[i].erase(parent[i]);
      graph[parent[i]].erase(i);
      if(i)bridges.push_back({i,parent[i]});
    }
  }

  idx = 0;
  for(int i = 0;i<n;i++){
    if(!vis[i]){
      SZ = 0;
      dfs_label(i);
      idx++;
      sz[label[i]] = SZ;
    }
  }
  
  for(int i = 0;i<n;i++)
    graph[i].clear(),vis[i] = false;

  for(auto v:bridges){
    int a = label[v.first],b = label[v.second];
    graph[a].insert(b);
    graph[b].insert(a);
  }

  build(n);
  
  while(q--){
    cin>>u>>v;
    u--,v--;

    if(getLen(label[u],label[v]) == getSize(label[u],label[v]))
      cout<<"YES"<<endl;
    else 
      cout<<"NO"<<endl;
  }
  
  return 0;
}  


