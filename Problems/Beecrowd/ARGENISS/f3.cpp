#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 

signed main(){__
    int T,n,s;  
    cin>>T;
    while(T--){
      cin>>n>>s;
      vector<int> nums(n);
      for(auto &c:nums)cin>>c;
      int ans = 0;
      for(int mask = 1;mask<(1<<n);mask++){
        int sum = 0,mn = 1e9,mx = -1e9;
        for(int j = 0;j<n;j++){
          if((mask>>j)&1){
            sum+=nums[j]*2;
            mn = min(j,mn);
            mx = max(j,mx);
          }
        }
        bitset<7> bs(mask);
        sum+=mx-mn;
        for(int j = 0;j<n;j++){
          if(!((mask>>j)&1))continue;
          int x = (sum-nums[j])+ min(j-mn,mx-j);
          if(x<=s)
            ans = max(ans,__builtin_popcount(mask));
        }
      }
      cout<<ans<<endl;
    }
    return 0;
}


