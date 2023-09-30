#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<pair<int,int>> graph2[maxn];
vector<int> graph[maxn];
vector<int> D;

const int inf = 1e18;
void dijkstra(int s,int n){
  for(int i = 0;i<n;i++){
    D[i] = inf;
  }
  D[s] = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto v:graph[u]){
      if(D[u]+1<D[v]){
        D[v] = D[u]+1;
        q.push(v);
      }
    }
  }
}

signed main(){__
  int n,m,u,v,c;
  cin>>n>>m;
  D.resize(n);
  for(int i = 0;i<m;i++){
    cin>>u>>v>>c;
    u--,v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
    graph2[u].push_back({v,c});
    graph2[v].push_back({u,c});
  }

  dijkstra(0,n);

  vector<int> nodes(n);
  iota(nodes.begin(),nodes.end(),0);

  sort(nodes.begin(),nodes.end(),[&](int a,int b){
      return D[a]<D[b];
      });

  int ans = 0;
  for(int i = 1;i<n;i++){
    int mn = 1e9;
    for(auto v:graph2[nodes[i]]){
      if(D[v.first]== D[nodes[i]]-1){
        mn = min(mn,v.second);
      }
    }
    ans+=mn*D[nodes[i]];
  }
  cout<<ans<<endl;
  return 0;
}

