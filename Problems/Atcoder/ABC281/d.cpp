#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[107][107][107];

vector<int> nums;
int n,d;
const int inf = -(1e16);
int solve(int idx,int k,int mod){
    if(idx == n && k == 0 && mod ==0 )return 0;
    if(idx == n && (k || mod))return inf;
    if(k==0 && mod==0)return 0;
    if(k==0)return inf;
    
    int &x = dp[idx][k][mod];
    if(x!=-1)return x;
    int ans = inf;
    ans = max(ans,solve(idx+1,k,mod));
    ans = max(ans,nums[idx]+solve(idx+1,k-1,(mod+nums[idx])%d));
    if(ans<0)ans = inf;
    return x = ans;
}

signed main(){__
    int T = 1,k;
    while(T--){
        cin>>n>>k>>d;
        nums.resize(n);
        for(auto &c:nums)cin>>c;    
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,k,0);
        if(ans==inf)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}