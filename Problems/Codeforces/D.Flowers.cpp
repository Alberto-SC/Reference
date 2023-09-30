#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int maxn = 100007;
lli dp[maxn];
const int mod = 1000000007;
#define MOD(n) ( ( ((n) % (mod)) + (mod) ) % (mod))
int k;
lli _get(lli n){
    if(n<0)return 0;
    else if(dp[n] != 0)return dp[n];
    lli &x = dp[n];
    x+= _get(n-1);
    x%=mod;
    x+=_get(n-k);
    x%=mod;
    return x;
}

int main(){
    int n,a,b;
    // memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    vector<lli> ac;
    ac.push_back(0);
    ac.push_back(1);
    dp[1] = 1;
    dp[0] = 1;
    if(k == 1)dp[1] = 2,ac[1] = 2;
    for(int i = 2;i<maxn;i++)
        _get(i);
    for(int i = 2;i<maxn;i++)
        ac.push_back((ac.back()+dp[i])%mod);
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        lli x = ac[b];
        x-=ac[a-1];
        x%=mod;
        // MOD(x);
        x = ((x%mod)+mod)%mod;
        cout<<x<<endl;
    }
    return 0;
}