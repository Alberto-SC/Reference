#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

signed main(){__
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  vector<int> f(m);
  for(int i = 0;i<n;i++){
    f[nums[i]%m]++;
  }
  int need = n/m;

  vector<pair<int,int>> can;
  multiset<int> nd;
  for(int i = 0;i<n;i++){
    if(f[nums[i]%m]>need){
      can.push_back({nums[i]%m,i});
      f[nums[i]%m]--;
    }
  }
  sort(can.rbegin(),can.rend());
  int ans = 0;
  for(int i = 0;i<m;i++){
    if(f[i]<need){
      int x = need-f[i];
      for(int j = 0;j<x;j++){
        auto x = can.back();
        if(x.first<i){
          ans+=i-x.first;
          nums[x.second]+=i-x.first;
          can.pop_back();
          f[i]++;
        }
      }
    }
  }
  reverse(can.begin(),can.end());
  for(int i = 0;i<m;i++){
    if(f[i]<need){
      int x = need-f[i];
      for(int j = 0;j<x;j++){
        auto x = can.back();
        ans+=(m-x.first)+i;
        nums[x.second]+=(m-x.first)+i;
        can.pop_back();
        f[i]++;
      }
    }
  }
  cout<<ans<<endl;
  for(auto c:nums)cout<<c<<" ";
  cout<<endl;
  return 0;
}
