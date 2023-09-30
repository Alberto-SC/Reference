#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 3007;
int D[maxn][maxn];
vector<int> p(maxn);
vector<int> sz(maxn,1);
vector<int> component[maxn];

struct edge{
  int u,v,c;
  bool operator <(edge &a){
    return c<a.c;
  }
};

int root(int u){
  return u ==p[u]? u:p[u] = root(p[u]);
}

signed main(){__
  int n,m,h,u,v,c;
  while(cin>>n>>m>>h){
    if(n==-1)break;
    vector<edge> E;
    for(int i = 0;i<m;i++){
      cin>>u>>v>>c;
      u--,v--;
      E.push_back({u,v,c});
    }
    sort(E.begin(),E.end());
    for(int i= 0;i<n;i++){
      sz[i] = 1;
      p[i] = i;
      component[i].clear();
      component[i].push_back(i);
    }

    for(int i = 0;i<m;i++){
      int u = E[i].u;
      int v = E[i].v;
      int c = E[i].c;
      int pu = root(u);
      int pv = root(v);
      if(pu == pv)continue;
      for(auto a:component[pu]){
        for(auto b:component[pv]){
          D[a][b] = c;
          D[b][a] = c;
        }
      }
      if(sz[pu]<sz[pv])swap(pu,pv);
      p[pv] = pu;
      sz[pu]+=sz[pv];
      for(auto a:component[pv]){
        component[pu].push_back(a);
      }
    }

    while(h--){
      cin>>u>>v;
      u--,v--;
      cout<<D[u][v]<<" ";
    }
    cout<<endl;
  }
    
  return 0;
}
