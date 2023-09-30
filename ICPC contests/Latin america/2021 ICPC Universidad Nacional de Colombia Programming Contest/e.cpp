#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> pos(1000007);
int l = 500000,r = l;
vector<int> rpos(1000007,-1);
const int maxn = 500007;
vector<int> graph[maxn];

void dfs(int u,int p=-1){
  int L = 0,R = 0; 
  int NEED = graph[u].size()/2;

  for(auto c:graph[u]){
    if(rpos[c]!=-1 && rpos[c]<rpos[u])L++;
    else if(rpos[c]!=-1 && rpos[c]>rpos[u])R++;
  }
  if(graph[u].size()&1){
    for(auto c:graph[u]){
      if(rpos[c]!=-1)continue;
      pos[r] = c;
      rpos[c] = r;
      r++;
    }
  }
  else{
    for(auto c:graph[u]){
      if(rpos[c]!=-1)continue;
      if(R!=NEED){
        pos[r] = c;
        rpos[c] = r;
        r++;
        R++;
      }
      else{
        pos[l] = c;
        rpos[c] = l;
        l--;
        L++;
      }
    }
  }
  for(auto v:graph[u]){
    if(v==p)continue;
    dfs(v,u);
  }
}

signed main(){__
  int n,u,v;
  cin>>n;
  for(int i = 0;i<n-1;i++){
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  pos[l] = 0;
  rpos[0] = l;
  l--,r++;
  dfs(0);
  for(int i = l+1;i<r;i++){
    cout<<pos[i]<<" ";  
  }
  cout<<endl;
  return  0;
}

