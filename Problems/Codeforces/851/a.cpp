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
    int s = 0;
    for(auto &c:nums){
      cin>>c;
      if(c == 1)c = 0;
      else if(c ==2)c = 1;
      s+=c;
    } 
    int ans = -1;
    int s2 = 0; 
    for(int i = 0;i<n;i++){
      s2+=nums[i];
      if((s-s2) == s2){
        ans = i+1;
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
