#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[300][2*(302*302)];

const int mod = 998244353;
vector<int> nums(307);
int n;
int off = (300*300)+2;
int solve(int idx,int sum = 0){
    if(idx == n-1){
        return 1;
    }
    int &x = dp[idx][sum+off];
    if(x!=-1)return x;

    int ans = 0;
    if(!sum){
        (ans+=solve(idx+1,nums[idx+1]))%=mod;
    }
    else{
        (ans+=solve(idx+1,nums[idx+1]-sum))%=mod;
        (ans+=solve(idx+1,nums[idx+1]+sum))%=mod;
    }
    return x = ans;
}

signed main(){__
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,nums[1])<<endl;
    return 0;
}