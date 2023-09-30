#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> nums;
const int maxn = 100007;
int dp[maxn][4][4];
int v[maxn][4][4];
int cur=2;
int solve(int idx,int prv1,int prv2){
  if(idx==nums.size())return 0;

  int &ans = dp[idx][prv1][prv2];
  int &vis = v[idx][prv1][prv2];

  if(vis==cur)return ans;
  vis=cur;

  ans=4e18;
  for(int i=0;i<3;i++){
    int x=nums[idx];
    int c=0;
    while(x%3!=i)x++,c++;

    if(prv1==3)ans=min(ans,solve(idx+1,i,prv2)+c);
    else if(prv2==3)ans=min(ans,solve(idx+1,prv1,i)+c);
    else if((i+prv1+prv2)%3==0)ans=min(ans,solve(idx+1,prv2,i)+c);
    
  }
  return ans;
}
signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;

    cout<<solve(0,3,3)<<endl;
    cur++;
  }
  return 0;
}