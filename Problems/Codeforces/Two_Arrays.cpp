#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1000000007;
vector<lli> factmod(2000);
int pow_mod(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) x = (x%mod*a%mod)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return x;
}

int main(){
    lli n,m;
    cin>>n>>m;
    factmod[1] = 1;
    factmod[0] = 1;
    for(lli i = 2;i<2000;i++)
        factmod[i] = (factmod[i-1]*i)%mod;

    lli mf = factmod[n+(2*m)-1];
    lli inv1 = pow_mod(factmod[2*m],mod-2);
    lli inv2 = pow_mod(factmod[n-1],mod-2);
    lli ans = (mf*((inv1*inv2)%mod))%mod;

    cout<<ans<<endl;
    return 0;
}