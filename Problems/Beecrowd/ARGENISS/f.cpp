#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 

int n,s;
vector<int> f;
int dp[13][1<<13][1<<12];
map<int,int> S;
int key = 0;
const int inf = 1e9;
int solve(int idx,int mask,int k){
  if(k<0)return -inf;
  if(k<f[idx])return 0;
  if(!S.count(k)){
    S[k] = key++;
  }
  int &x = dp[idx][mask][k];
  if(x!=-1)return x;
  int ans = 0;
  for(int i = 0;i<n;i++){
    if((mask>>i)&1|| i==idx)continue;
    ans = max(ans,solve(i,mask|1<<idx,k-((2*f[idx])+abs(i-idx))));
  }
  return x = ans+1;
}

signed main(){__
    int T;  
    cin>>T;
    while(T--){
      cin>>n>>s;
      f.resize(n);
      for(auto &c:f)cin>>c;
      int ans = 0;
      memset(dp,-1,sizeof(dp));
      cout<<solve(2,0,s)<<endl;;
      for(int i = 0;i<n;i++){
        //ans = max(ans,solve(i,0,s));
      }
      //cout<<ans<<endl;
    }
    return 0;
}

