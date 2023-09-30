#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  int sum = 0;
  for(auto &c:nums)cin>>c,sum+=c;
  int ans = 1e18;
  for(int mask = 0;mask<(1<<n);mask++){
    int s = 0;
    for(int i = 0;i<n;i++){
      if((mask>>i)&1)s+=nums[i];
    }
    ans = min(ans,abs(s-(sum-s)));
  }
  cout<<ans<<endl;
}


