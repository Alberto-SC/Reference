#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int solve(int x,vector<int> &nums){
  int mx = 0;
  int n = nums.size();
  for(int i = 0;i<n;){
    int j = i;
    int sum = 0;
    while(j<n && sum<x){
      sum+=nums[j++];
    }
    if(sum!=x)return 1e9;
    mx = max(mx,j-i);
    i = j;
  }
  return mx;
}

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    int sum = 0;
    for(auto &c:nums)cin>>c,sum+=c;
    int ans = 1e9;
    for(int i = 1;i*i<=sum;i++){
      if(sum%i==0){
        ans = min(ans,solve(i,nums));
        if(sum/i!= i)ans = min(ans,solve(sum/i,nums));
      }
    }
    cout<<ans<<endl;
  }
  
  return 0;
}

