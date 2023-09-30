#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

int dp[2007][2007];

char M[2007][2007];
const int mod = 998244353;

int n,m;
int solve(int x,int y){
    if(x== n-1 && y == m-1)return 1;

    int &X = dp[x][y];
    if(X != -1)return X;

    int ans = 0;
    
    if(x != n-1){
        if(M[x][y]== 'Y' && M[x+1][y] == 'Y')
            ans+=4*solve(x+1,y);
        else 
            ans+= solve(x+1,y);
        ans%=mod;
    }
    if(y != m-1){ 
        if(M[x][y]== 'Y' && M[x][y+1] == 'Y')
            ans+=4*solve(x,y+1);
        else 
            ans+= solve(x,y+1);
        ans%=mod;
    }
    ans%=mod;
    return X = ans;
}

signed main(){__
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;
    return 0;
}

