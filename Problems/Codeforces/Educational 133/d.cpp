#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;
signed main(){__
    int T = 1,n,k;
    while(T--){
        cin>>n>>k;
        vector<int> dp(n+1);
        dp[0] = 1;
        vector<int> ans(n+1);
        int sum = 0;
        for(int i = 0;i<=n;){
            vector<int> ndp(n+1);
            vector<int> sum(k);
            if(i+k>n)break;
            for(int j = i;j<=n;j++){
                ndp[j] = sum[j%k];
                sum[j%k] += dp[j];
                sum[j%k]%=mod;
                ans[j] += ndp[j];
                ans[j]%=mod;
            }
            dp = ndp;
            i+=k;
            k++;
        }
        for(int i = 1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}