#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double

// ld dp[50][50][50][50];
map<tuple<int,int,int,int>,ld> mp;
int a,b,c,n;
vector<int> nums;

ld solve(int idx,int sa,int sb,int sc){
  if(idx == n){
    return max({sa/(a*1.0),sb/(b*1.0),sc/(c*1.0)});
  }
  if(mp.count({idx,sa,sb,sc}))return mp[{idx,sa,sb,sc}];
  // ld &x = dp[idx][sa][sb][sc];
  // if(x !=0)return x;

  ld ans = 1e9;
  ans = min(ans,solve(idx+1,sa+nums[idx],sb,sc));
  ans = min(ans,solve(idx+1,sa,sb+nums[idx],sc));
  ans = min(ans,solve(idx+1,sa,sb,sc+nums[idx]));

  return mp[{idx,sa,sb,sc}]=ans;
  // return x= ans;
}
ld dp2[500][500][500];

signed main(){__
  cin>>n>>a>>b>>c;
  nums.resize(n);
  for(auto &c:nums)cin>>c;
  // memset(dp,0,sizeof(dp));
  // memset(dp2,0,sizeof(dp));
  ld ans = solve(0,0,0,0);
  cout<<ceil(ans)<<endl;

}