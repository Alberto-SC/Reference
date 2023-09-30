#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 

int n,s;
vector<int> f;
int ans = 0;
map<int,int> S;

void solve(int idx,int mask,int k,int d = 0){
  if(k<0|| k<f[idx])return;
  ans = max(ans,d+1);
  for(int i = 0;i<n;i++){
    if((mask>>i)&1|| i==idx)continue;
    solve(i,mask|1<<i,k-((2*f[idx])+abs(i-idx)),d+1);
  }
}

signed main() {__
    int T;
    cin>>T;
    while(T--){
      cin>>n>>s;
      f.resize(n);
      for(auto &c:f)cin>>c;
      ans = 0;
      for(int i = 0;i<n;i++){
        solve(i,0,s);
      }
      cout<<ans<<endl;
    }
    return 0;
}


