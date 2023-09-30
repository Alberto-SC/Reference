#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double

ld dp[50][501][501];
int a,b,c,n;
vector<int> nums;
int total;

ld solve(int idx,int sa,int sb){
  if(idx == n){
    return max({sa/(a*1.0),sb/(b*1.0),(total-(sa+sb))/(c*1.0)});
  }
  ld &x = dp[idx][sa][sb];
  if(x !=0)return x;

  ld ans = 1e9;
  ans = min(ans,solve(idx+1,sa+nums[idx],sb));
  ans = min(ans,solve(idx+1,sa,sb+nums[idx]));
  ans = min(ans,solve(idx+1,sa,sb));

  return x=ans;
}

signed main(){__
  cin>>n>>a>>b>>c;
  nums.resize(n);
  for(auto &c:nums)cin>>c,total+=c;
 
  memset(dp,0,sizeof(dp));
  ld ans = solve(0,0,0);
 
  cout<<ceil(ans)<<endl;
}