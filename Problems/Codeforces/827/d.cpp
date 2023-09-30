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
    vector<int> last(1001);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
      last[nums[i]] = i+1;
    }
    set<int> st(nums.begin(),nums.end());
    int ans = -1;
    for(auto d:st){
      for(auto c:st){
        if(__gcd(d,c)==1){
          ans = max(ans,last[d]+last[c]);
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

