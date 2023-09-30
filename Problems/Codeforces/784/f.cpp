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
    for(auto &c:nums)cin>>c;
    int ans = 0;
    vector<int> suff(n);
    suff[n-1] = nums[n-1];
    for(int i = n-2;i>=0;i--)
      suff[i] = suff[i+1]+nums[i]; 
    int s = 0;
    for(int i = 0;i<n;i++){
      s +=nums[i];
      int l = i;
      int r = n;
      while (l+1<r){
        int m = (l+r)>>1;
        if(suff[m]<=s)
          r = m;
        else 
          l = m;
      }
      if(r<n && suff[r] == s)ans = max(ans,i+1+(n-r));
    }
    cout<<ans<<endl;
  }
  return 0;
}
