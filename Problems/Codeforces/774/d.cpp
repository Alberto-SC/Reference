#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 30007;
vector<int> p(maxn);
vector<int> sz(maxn,1);

int root(int u){
  return p[u]== u? u:root(p[u]);
}

void union_by_sz(int u,int v){
  u = root(u);
  v = root(v);
  if(u == v)return ;
  sz[v]+=sz[u];
  p[u] = v;
}

signed main(){
  int n,m,x,y;
  char c;
  cin>>n>>m;
  iota(p.begin(),p.end(),0);
  for(int i= 0;i<m;i++){
    cin>>c;
    if(c=='M'){
      cin>>x>>y;
      union_by_sz(x,y);
      for(int i = 0;i<n;i++)
        cout<<p[i]<<" ";
        cout<<endl;
    }
    else{
      cin>>x;
      if(p[x]!=x)cout<<0<<endl;
      else 
        cout<<sz[p[x]]<<endl;
    }
  }
}