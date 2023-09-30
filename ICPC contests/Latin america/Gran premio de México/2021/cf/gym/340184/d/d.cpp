#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int> (4));
    for(int i = 0;i<n;i++)
        cin>>dp[i][0]>>dp[i][1]>>dp[i][2]>>dp[i][3];
    for(int j = 0;j<4;j++){
        for(int i = 0;i<n;i++){
            if(i)
                dp[i][j] = dp[i][j]+dp[i-1][j];
            else if(j)
                dp[i][j]+=dp[i][j-1];
        }
    }
    cout<<dp[n-1][3]<<endl;
    return 0;
}  
