#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> nums(n);
    int mn = 1e9;
    for(auto &c:nums)cin>>c,mn = min(c,mn);
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans+= nums[i]-mn;
    }
    cout<<ans<<endl;
  }
  return 0;
}
