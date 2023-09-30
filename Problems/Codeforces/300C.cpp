#include <bits/stdc++.h>
using namespace std;
const int    MAX = 1e6 + 100;
int mod = 1e9+7;
typedef long long int lli;
long long  fact[MAX];

lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1)x = (x*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return x;
}

void prefact(){
    fact[0] = 1;
    for(int i = 1;i<MAX; i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=mod;
    }
}
bool check(lli val, lli a ,lli b){
    while(val){
        if(val%10 == a|| val%10 == b)
            val/=10;
        else return false;
    }
    return true;
}
lli getc(lli i,lli n){
    lli ans = fact[n];
    lli div = fact[n-i]*fact[i];
    div%=mod;
    div = mod_pow(div,mod-2);
    return (ans*div)%mod;
}
int main(){
    lli a,b,n;
    lli ans = 0;
    cin>>a>>b>>n;
    prefact();
    for(int i = 0;i<=n;i++){
        lli ch = (a*i)+(b*(n-i));
        if(check(ch,a,b)){ 
        ans += getc(i,n);
        ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}