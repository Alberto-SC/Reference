#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int mod = 1000000007;
const int MAXN =1007;
lli inv[MAXN];
lli fact[MAXN];
lli invfact[MAXN];
void calc(int m){
    inv[0] = inv[1] = 1;
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i <= m; ++i) {
        inv[i] = (inv[mod % i]* (mod - (mod/i)))%mod;
        fact[i] = (fact[i - 1]* i)%mod;
        invfact[i] = (invfact[i - 1]* inv[i])%mod;
    }
}
lli binomial_coefficient(int n, int k) {
    return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
}
int main(){
    int a,b,c,k;
    cin>>a>>b>>k>>c;
    if(c != a && c!= b)return cout<<0<<endl,0;
    if(a == b)return cout<<k<<endl,0;
    calc(k);
    lli ans = 0;
    for(int i = 1;i<=k;i++)
        ans = (ans+((binomial_coefficient(k,i)*i)%mod))%mod;
    cout<<ans<<endl;
    return 0;
}