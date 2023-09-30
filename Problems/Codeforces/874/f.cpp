#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int mod_pow(int a,int b){
  int x = 1;
  while(b){
    if(b&1)(x*=a)%=mod;
    (a*=a)%=mod;
    b>>=1;
  }
  return x;
}

signed main(){__
  int T = 1,n,m;
  cin>>T;
  while(T--){
    cin>>n>>m;
    vector<int> nums(n);
    map<int,int> mp;
    for(auto &c:nums)cin>>c,mp[c]++;

    vector<int> v;
    vector<int> ac;
    for(auto c:mp){
      v.push_back(c.first);
      ac.push_back(c.second);
    }

    for(int i = 1;i<ac.size();i++)(ac[i]*=ac[i-1])%=mod;

    int ans = 0;

    for(int i = 0;i<v.size();i++){
      int nxt = lower_bound(v.begin(),v.end(),v[i]+m) - v.begin();
      int c = nxt-i;
      if(c<m)continue;
      int p = i?(ac[nxt-1]*mod_pow(ac[i-1],mod-2))%mod:ac[nxt-1];
      (ans+=p)%=mod;
    }

    cout<<ans<<endl;
  }
  return 0;
}