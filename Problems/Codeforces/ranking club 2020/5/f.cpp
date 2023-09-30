#include <bits/stdc++.h>
using namespace std;
const int inf = -1000000007;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<vector<int>> dp(2,vector<int>(n,inf));
    // dp[0][n-1] = nums[n-1];
    dp[1][n-1] = nums[n-1];
    bool lastsign;
    nums[n-1]<0?lastsign = false:lastsign =true;
    for(int i = n-2;i>=0;i--){
        if(nums[i]<0){
            if(lastsign)
                dp[!nums[i]<0][i] = max(dp[lastsign][i+1],dp[!lastsign][i+1]+nums[i]);
            else 
                dp[!nums[i]<0][i] = dp[lastsign][i+1];
            lastsign = false;
        }
        else{
            if(lastsign)
                dp[!nums[i]<0][i] = dp[lastsign][i+1];
            else 
                dp[!nums[i]<0][i] = max(dp[lastsign][i+1],dp[!lastsign][i+1]+nums[i]);
            lastsign = true;
        }
    }
    for(int i = 0 ;i<2;i++){
        for(int j = 0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<max(dp[0][0],dp[1][0])<<endl;

    return 0;
}