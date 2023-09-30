#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<bool> used(n);
    vector<int> ans ;
    int orPref = 0;
    while(1){
      int mx  = orPref,idx = -1;
      for(int i = 0;i<n;i++){
        if(used[i])continue;
        int x = orPref|nums[i];
        if(x>mx){
          mx = x;
          idx = i;
        }
      }

      if(mx ==orPref){
        break;
      }
      orPref = mx;
      used[idx] = true;
      ans.push_back(nums[idx]);
    }
    for(int i = 0;i<n;i++)
      if(!used[i])ans.push_back(nums[i]);
  
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    
  }
  return 0;
}

