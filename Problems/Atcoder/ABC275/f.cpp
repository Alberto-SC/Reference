#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int n,m;
int dp[3007][3007][2];
vector<int> nums;
const int INF = 1e9;
int solve(int idx,int sum,int f = 1){
    if(idx == n && sum==0)return dp[idx][sum][f] = f==0;
    if(idx == n && sum)return INF;
    if(sum<0)return INF;

    int &x = dp[idx][sum][f];
    if(x !=-1)return x;
    
    int ans = 0;  
    ans = min((f==0)+solve(idx+1,sum-nums[idx],1),solve(idx+1,sum,0));
    return x= ans;
}

signed main(){__
    cin>>n>>m;
    nums.resize(n);
    int sum = 0;
    for(auto &c:nums)cin>>c,sum+=c;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i<=m;i++){
        int ans = solve(0,i);
        if(ans==INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    cout<<endl;
    return 0;
}