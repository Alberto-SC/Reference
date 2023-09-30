#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> M(3);
vector<int> nums(maxn);
int n;

const int inf = 4e18;
vector<vector<int>> dp(maxn,vector<int>(3,-inf));
int solve(int idx,int k){
    if(k == 3)return 0;
    if(idx == n)return -inf;
    int &x = dp[idx][k];
    if(x !=-inf)return x;
    int res = -inf;
    res = max(solve(idx+1,k),solve(idx+1,k+1)+nums[idx]*M[k]);
    res = max(res,solve(idx,k+1)+nums[idx]*M[k]);
    return x = res;
}
signed main(){__
    cin>>n;
    cin>>M[0]>>M[1]>>M[2];
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    
    cout<<solve(0,0);
    return 0;
}  
