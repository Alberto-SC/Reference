#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 507;
vector<int> graph[maxn];
vector<bool> vis(maxn);
int cont  = 0;
void dfs(int u){
  vis[u] = true;
  cont++;
  for(auto v:graph[u]){
    if(!vis[v])dfs(v);
  }
}

signed main(){__
  int n,x,k,v;
  cin>>n>>k;
  for(int i = 0;i<n;i++){
    cin>>x;
    for(int j = 0;j<x;j++){
      cin>>v;
      v--;
      graph[v].push_back(i);
    }
  }
  vector<int> ans(n,0);
  for(int i = 0;i<n;i++){
    cont = 0;
    vis.assign(n,false);
    dfs(i);
    if(cont>k)ans[i] = 1;
  }
  for(auto c:ans)cout<<c<<endl;
  cout<<endl;
  return 0;
}
