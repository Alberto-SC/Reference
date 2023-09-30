#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,c--;
    int dp[n][64];
    for(int i = 0;i<n;i++)
        dp[i][0] =nums[i];
     
    for(int i = 1;i<64;i++){
        for(int j = 0;j<n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    int ans = 0;
    for(int i =63;i>=0;i--){
        if((k>>i)&1)
            ans = dp[ans][i];
    }
    cout<<ans+1<<endl;
    return 0;
}