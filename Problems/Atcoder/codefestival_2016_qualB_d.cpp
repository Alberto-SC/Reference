#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long
signed main(){__
  int n;
  cin>>n;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  int ans = nums[0]-1,P = 2;
  for(int i = 1;i<n;i++){
      if(nums[i]== P)P++;
      if(nums[i]<P)continue;
      ans+= (nums[i]-1)/P;
  }
  cout<<ans<<endl;
  return 0;
}


