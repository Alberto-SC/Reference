#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<vector<int>> dp;
string s;
vector<int> nums;
int n;
const int inf = 1e9;
int solve(int idx,int c){
    if(idx == -1)return 0;
    int &x = dp[idx][c];
    if(x !=-1)return x;

    int ans = inf;
    if(c){
        if(s[idx]== '1')
            ans = min(ans,solve(idx-1,c));
        ans = min(ans,solve(idx-1,0));
    }
    else{
        if(s[idx]== '1')
            ans = min(ans,solve(idx-1,1)+nums[idx]);
        ans = min(ans,solve(idx-1,0)+nums[idx]*(s[idx]=='0'));
    }
    return x = ans;
}


signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        int sum = 0;
        nums.resize(n);
        for(auto &c:nums)cin>>c,sum+=c;
        dp.assign(n,vector<int>(2,-1));
        // cout<<sum<<" "<<solve(n-1,s[n-1]=='1')<<endl;
        cout<<sum-solve(n-1,0)<<endl;
    }
    return 0;
}