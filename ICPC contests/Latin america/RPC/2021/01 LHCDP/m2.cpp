#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
typedef long long int lli;
const lli mod = 2147483647;

lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
int main(){__
    lli n,t;
    cin>>t;
    lli inv2 = mod_pow(2,mod-2);
    lli inv6 = mod_pow(6,mod-2);
    while(t--){
        cin>>n;
        lli x = ((n%mod)*((n+1)%mod))%mod;
        x= ((x%mod)*(((2*n)+1)%mod))%mod;
        (x*=inv6)%=mod;
        lli y = ((n%mod)*((n+1)%mod))%mod;
        (y*=inv2)%=mod;
        lli ans = (x+y)%mod;
        (ans*=inv2)%=mod;
        cout<<ans<<endl;
    }
    return 0;
}