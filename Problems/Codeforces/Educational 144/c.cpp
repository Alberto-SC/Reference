#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';
#define int long long
using namespace std;

const int MX = 1000000;
int dp[21][MX+1];

const int mod = 998244353;

signed main(){__
    int T,n;
    cin>>T;

    for(int i = 1;i<=MX;i++)
        dp[1][i] = 1;
    
    
    for(int s = 1;s<=20;s++){
        for(int j = 1;j<=MX;j++){
            for(int k = 2;j*k<=MX;k++){
                dp[s+1][j*k]+=dp[s][j];
                dp[s+1][j*k]%=mod;
            }
        }
    }

    for(int s = 1;s<=20;s++){
        for(int j = 1;j<=MX;j++){
            dp[s][j]+=dp[s][j-1];
            dp[s][j]%=mod;
        }
    }

    while(T--){
        int l,r;
        cin>>l>>r;
        
        int x = l;
        int cont = 0;
        while(x<=r){
            x*=2;
            cont++;
        }
        int ans = 0;
        int c = 0;
        for(int i = l;i<=r;i++){
            int y = r/i;
            c++;
            if(dp[cont][y]==0)break;
            ans+=dp[cont][y];
        }
        cout<<cont<<" "<<ans<<" "<<c<<endl;
    }

    return 0;
}

