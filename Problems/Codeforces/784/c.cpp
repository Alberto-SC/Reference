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
    bool f1 = true;
    bool f2 = true;
    for(int i= 2;i<n;i+=2)
      if((nums[i]&1) != (nums[i-2]&1))f1 = false;
    for(int i= 3;i<n;i+=2)
      if((nums[i]&1) != (nums[i-2]&1))f2 = false;
    if(f1 &&f2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  return 0;
}
