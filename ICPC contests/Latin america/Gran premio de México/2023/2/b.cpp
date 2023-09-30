#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
const int N = 1000007;

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
  int T = 1,n,q,id,v;
  vector<int> fact(N);

  fact[0] = 1;
  for(int i = 1;i<N;i++){
    fact[i] = fact[i-1]*i;
    fact[i]%=mod;
  }


  cin>>n>>q;
  vector<int> nums(n);
  map<int,int> mp;

  int x = 1; 
  for(auto &c:nums)cin>>c,mp[c]++;

  for(auto c:mp){
    (x*=fact[c.second])%=mod;
  }

  cout<<(x*mod_pow(fact[n],mod-2)%mod)<<endl;

  while(q--){
    cin>>id>>v;
    id--;
    if(nums[id] == v){
      cout<<(x*mod_pow(fact[n],mod-2))%mod<<endl;
      continue;
    }
    (x*=mod_pow(fact[mp[nums[id]]],mod-2))%=mod;
    mp[nums[id]]--;
    (x*=fact[mp[nums[id]]])%=mod;
    
    if(mp[v])
      (x*=mod_pow(fact[mp[v]],mod-2))%=mod;
    mp[v]++;
    (x*=fact[mp[v]])%=mod;
    nums[id] = v;

    cout<<(x*mod_pow(fact[n],mod-2))%mod<<endl;
  }

}