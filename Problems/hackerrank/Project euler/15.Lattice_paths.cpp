#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int n,m; 
const int mod = 1e9+7;

int dp[507][507];
int solve(int x,int y){
    if(x>n || y>m)return 0;
    int &res = dp[x][y];
    if(res!= -1)return res;
    int ans = 0;
    (ans+=solve(x+1,y))%=mod;
    (ans+=solve(x,y+1))%=mod;
    return res = ans;
}

signed main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                dp[i][j] = -1;
            }
        }
        dp[n][m] = 1;
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
