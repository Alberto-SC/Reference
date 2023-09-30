#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<vector<int>> dp(n,vector<int>(n));
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j<i)dp[i][j] = 0;
                if(j==i)dp[i][j] = a[i]*b[i];
            }
        }
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<(n-i)+1;j++){
                dp[j][(j+i)-1] = dp[j+1][(j+i)-2]+(a[j]*b[(j+i)-1])+(a[(j+i)-1]*b[j]);
            }
        }
        vector<int> pref(n);
        vector<int> suf(n);
        for(int i = 0;i<n;i++)
            pref[i] = a[i]*b[i]+(i?pref[i-1]:0);
        for(int i = n-1;i>=0;i--)
            suf[i]= a[i]*b[i]+(i==n-1?0:suf[i+1]);
        int ans = suf[0];
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                ans = max(ans,dp[i][j]+(i?pref[i-1]:0)+(j==n-1?0:suf[j+1]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
