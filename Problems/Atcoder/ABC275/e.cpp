#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1007][1007];

const int mod = 998244353;

int M,n;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

int solve(int idx,int k){
    if(idx == n && k == 0)return 1;
    if(idx == n && k)return 0;
    if(k ==0 && idx!=n)return 0;
    if(k<0)return 0;

    int &x = dp[idx][k];
    if(x != -1)return x;
    int ans = 0;
    for(int i= 1;i<=M;i++){
        int nxt = i+idx;
        if(nxt>n)
            nxt= idx-(nxt-n);
        (ans+=solve(nxt,k-1))%=mod;
    }
    return x = ans;
}

signed main(){__
    int k;
    cin>>n>>M>>k;
    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i =1;i<=k;i++){
        int x = solve(0,i);
        int Mi = mod_pow(M,k-i);
        x*=Mi;
        x%=mod;
        (ans+=x)%=mod;
    }
    int invX = mod_pow(mod_pow(M,k),mod-2);
    ans*=invX;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}