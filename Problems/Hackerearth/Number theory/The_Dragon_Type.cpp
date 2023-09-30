#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int mod_pow(int a,int b,int mod){
  int x = 1;
  while(b){
    if(b&1)(x*=a)%=mod;
    (a*=a)%=mod;
    b>>=1;
  }
  return x;
}       

signed main(){__
  int n,p;
  cin>>n>>p;
  vector<int> nums(n);
  vector<int> mp(p);
  for(auto &c:nums)cin>>c,mp[c%p]++;
  int ans=mp[0];
  vector<int> used(p);
  for(int i = 1;i<p;i++){
    int bad = mod_pow(i,p-2,p);
    if(used[i])continue;
    if(bad== i)continue;
    ans+=max(mp[i],mp[bad]);
    used[bad] = true;
  }
  cout<<ans<<endl;
  return 0;
}

