#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int mn = nums[0];
    int mx = nums.back();
    int idx = n-2;
    int best = 0;
    while(idx>0){
      best = max(best,(mx-nums[idx])+(mx-mn));
      mx = nums[idx--];
    }

    idx = 1;
    mx = nums.back();
    while(idx<n-1){
      best = max(best,(nums[idx]-mn)+(mx-mn));
      mn = nums[idx++];
    }
    cout<<best<<endl;
  }
  return 0;
}
