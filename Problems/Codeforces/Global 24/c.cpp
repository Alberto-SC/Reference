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
    int ans = n/2;
    for(int i = 0;i<n;){
      int j = i;
      while(j<n && nums[i]== nums[j]){
        j++;
      }
      ans = max(ans,j*(n-j));
      i = j;
    }
    cout<<ans<<endl;
  }
  return 0;
}
