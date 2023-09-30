#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod= 998244353;

int dp[5007][5007];

int solve(int a,int b){
    if(a==0 || b==0)return 1;
    int &x = dp[a][b];
,     if(x!= 0)return x;
    int res = 0;
    res = (b*solve(a-1,b-1)+solve(a-1,b))%mod;
    return x = res;
}

signed main(){__
	int t= 1,n,k,a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    memset(dp,0,sizeof(dp));
    (ans=solve(max(a,b),min(a,b)))%=mod;
    (ans*=solve(max(a,c),min(a,c)))%=mod;
    (ans*=solve(max(b,c),min(b,c)))%=mod;
    cout<<ans<<endl;
    return 0;
}  
