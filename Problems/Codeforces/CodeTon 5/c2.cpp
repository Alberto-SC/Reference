#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> nums;
map<int,vector<int>> mp;

vector<int> dp;
int solve(int idx){
  if(idx == nums.size())return 0;

  int &x = dp[idx];
  if(x !=-1)return x;
  int ans = 0;

  for(auto c:mp[nums[idx]]){
    if(c>idx)
      ans = max(ans,(c-idx)+1+solve(c+1));
  }
  ans = max(ans,solve(idx+1));
  return x = ans;
}

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    nums.resize(n);
    mp.clear();
    dp.assign(n+1,-1);
    for(auto &c:nums)cin>>c;

    for(int i = 0;i<n;i++)
      mp[nums[i]].push_back(i);

    cout<<solve(0)<<endl;
  }
  return 0;
}