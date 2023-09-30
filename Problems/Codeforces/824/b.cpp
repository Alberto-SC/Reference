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
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int x = (nums[0]*2)-1;
    int ans = 0;
    for(int i = 1;i<n;i++){
      ans+=nums[i]/x;
      if(nums[i]%x ==0)ans--;
    }
    cout<<ans<<endl;
  }
  return 0;
}
