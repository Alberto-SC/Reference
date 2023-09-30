#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[200007];

const int mod = 998244353;
int inv100,a,b;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
int p;
int solve(int n){
    if(n==1)return 1;
    if(n==0)return 0;
    int &x = dp[n];
    if(x!=-1)return x;
    x = 1+((a*solve(n-2))%mod)+((b*solve(n-1))%mod);
    x%=mod;
    return x;
}

signed main(){__
    int n;
    cin>>n>>p;
    inv100=  mod_pow(100,mod-2);
    a = p*inv100;
    a%=mod;
    b = (100-p)*inv100;
    b%=mod;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n)<<endl;
    return 0;
}