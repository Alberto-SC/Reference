#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    map<int,int> mp;
    for(auto &c:nums)cin>>c,mp[c]++;
    sort(nums.begin(),nums.end());
    if(nums[0] ==nums.back()){
      cout<<n*(n-1)<<endl;
    }
    else
      cout<<2*(mp[nums[0]]*mp[nums.back()])<<endl;
  }
  return 0;
}
