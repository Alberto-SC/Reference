#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> value(maxn);

map<pair<int,int>,int> mp;

int dfs(int u,int k){
  if(!k)return 0;
  if(mp.count({u,k}))return mp[{u,k}]; 
   
  int &res = mp[{u,k}];
  res = k*value[u];
    

  int c = graph[u].size();
  if(c==0)return res;
  int x = k/c;
  int cont = k%c;
  vector<int> best;
  for(auto v:graph[u]){
    int ans = dfs(v,x);
    res+=ans;
    best.push_back(dfs(v,x+(cont>=1))-ans);
  }
  sort(best.rbegin(),best.rend());
  for(int i = 0;i<cont;i++)
    res+=best[i];
  return res;  
}

signed main(){__
  int T,n,p,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
      graph[i].clear();
    }
    for(int i = 0;i<n-1;i++){
      cin>>p;
      p--;
      graph[p].push_back(i+1);
    }
    for(int i = 0;i<n;i++){
      cin>>value[i];
    }
    mp.clear();
    cout<<dfs(0,k)<<endl;
  }
  return 0;
}
