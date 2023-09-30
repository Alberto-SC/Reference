#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    vector<int> dp(n+1,1e12);
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        for(int s = 2;(s*(s-1))/2<=i;s++){
            dp[i] = min(dp[i],dp[i- (s*(s-1))/2]+s);
        }
    }
    cout<<dp[n]<<" "<<((dp[n]*(dp[n]-1))/2)-n<<endl;
    return 0;
}