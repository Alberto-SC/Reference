#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const lli mod = 1e9+7;
int main(){__
    int n,m,k;
    cin>>n>>m>>k;
    if(m>n)swap(n,m);
    lli DP[n+1][k+1];
    for(int i = 0;i<=n;i++)for(int j = 0;j<=k;j++)DP[i][j] = 0;
    for(int i = 1;i<=n;i++)
        DP[i][0] = 1;

    for(int i = 1;i<=k;i++){
        lli s = 0,ac = 0;
        for(int j = 1;j<=n;j++){
            DP[j][i] = ac;
            (s+=DP[j-1][i-1])%=mod;
            (ac+=s)%=mod;
        }   
    }
    // for(int j = 0;j<=k;j++)
    //     for(int i = 0;i<=n;i++)
    //         cout<<DP[i][j]<<" \n"[i ==n];
    // cout<<endl;
    lli ans = DP[n][k]*DP[m][k];
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}