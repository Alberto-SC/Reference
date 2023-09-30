#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int n,k;
vector<int> nums;

int dist(int i,int j){
    return abs(nums[i]-nums[j])+ (j-i)*(j-i);
}
const int maxn = 20007;
vector<int> dp(maxn,-1);
int solve(int idx){
    if(idx==n-1)return 0;
    int &x = dp[idx];
    if(x!=-1)return x;
    int ans = 1e15;
    for(int i = idx+1;i<=min(n-1,idx+k);i++)
        ans = min(ans,dist(i,idx)+solve(i));
    return x = ans;
}

signed main(){__
    cin>>n>>k;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    cout<<solve(0)<<endl;
}   