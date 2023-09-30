#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 1000007;
vector<int> graph[maxn];
vector<int> g(maxn);
vector<int> ans(maxn);
map<int,int> mp;

void dfs(int u,int p =-1){
  mp[g[u]]++;
  ans[u] = mp.size();
  for(auto v:graph[u]){
    if(v==p)continue;
    dfs(v,u);
  }
  mp[g[u]]--;
  if(mp[g[u]]==0)mp.erase(g[u]);
}



signed main(){__
  int T = 1,n,p;
  cin>>n;
  int root;
  for(int i = 0;i<n;i++){
    cin>>p;
    if(p== 0){
      root = i;
      continue;
    }
    graph[i].push_back(p-1);
    graph[p-1].push_back(i);
  }

  for(int i = 0;i<n;i++)cin>>g[i];

  dfs(root);
  for(int i = 0;i<n;i++)cout<<ans[i]<<" ";
  cout<<endl;
 
  return 0;
}