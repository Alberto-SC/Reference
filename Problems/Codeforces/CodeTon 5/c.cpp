#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int solve(vector<int> &nums){
  int n = nums.size();
  vector<int> F(n+1,-1);
  vector<pair<int,int>> v;

  for(int i = 0;i<n;i++){
    if(F[nums[i]] ==-1)F[nums[i]] = i;
    else {
      v.push_back({F[nums[i]],i});
      F[nums[i]] = i;
    }
  }

  sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
  });

  int N = v.size();

  if(N == 0)
    return 0;
  
  vector<int> B(N);
  for(int i = 0;i<N;i++){
    B[i] = v[i].second;
  }
  vector<int> dp(N);

  for(int i = 0;i<N;i++){
    int w = v[i].second-v[i].first+1;
    int idx = upper_bound(B.begin(),B.end(),v[i].first)-B.begin();
    
    if(idx == 0)dp[i] = w;
    else {
      if(B[idx-1] < v[i].first)
        dp[i] = w+dp[idx-1]; 
      else {

        dp[i] = w+dp[idx-1]-1;
        if(idx-2>=0)
        dp[i] = max(dp[i],w+dp[idx-2]);
      }
    }
    dp[i] = max(dp[i],(i?dp[i-1]:0));
  }

  return dp[N-1];
}

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    int ans = solve(nums);
    reverse(nums.begin(),nums.end());
    ans = max(ans,solve(nums));
    cout<<ans<<endl;
  }
  return 0;
}