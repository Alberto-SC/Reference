#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.rbegin(),nums.rend());
    int sum = 0;
    for(int i = 0;i<k;i++){
      sum+=nums[i];
    }
    cout<<sum<<endl;
  }
  return 0;
}
