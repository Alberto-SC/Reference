#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    if(k ==n){
      cout<<1000000000<<endl;
      continue;
    }
    vector<int> a= nums;
    sort(a.begin(),a.end());
    map<int,int> mp;
    for(int i = 0;i<k;i++){
      mp[a[i]]++;
    }
    for(int i = 0;i<n;i++){
      if(mp[nums[i]]>0){
        mp[nums[i]]--;
        nums[i] = 1e9;
      }
    }
    int mn = a[k];
    int ans = 0;
    for(int i = 0;i<n;i++){
      ans = max(ans,min({nums[i],nums[i+1],2*mn}));
    }
    cout<<ans<<endl;
  }
  return 0;
}
