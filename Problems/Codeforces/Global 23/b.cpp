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
    vector<int> z;
    for(int i= 0;i<n;i++){
      if(nums[i]==0)z.push_back(i);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
      if(z.size()==0)break;
      if(nums[i]==1){
        int last = z.back();
        if(last>i){
          ans++;
          z.pop_back();
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
