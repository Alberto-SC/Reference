#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,r,c,k;
  cin>>r>>c>>k;

  vector<int> nums(c);
  map<int,int> mp;
  for(auto &x:nums)cin>>x,mp[x]++;

  vector<int> v;
  for(auto d:mp){
    v.push_back(d.second);
  }
  sort(v.rbegin(),v.rend());
  int ans = 0;
  for(int i = 0;i<min(k,(int)v.size());i++){
    ans+=v[i];
  }
  cout<<ans<<endl;
  return 0;
}