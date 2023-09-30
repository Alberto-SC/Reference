#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1000000007;
lli mod_pow(lli a,lli b,lli m){
    lli x = 1;
    while(b){
        if(b&1)x = (a*x)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return x;
}

int main(){
    lli n;
    cin>>n;
    lli l = 1,r = 1000000000;
    while(l+1<r){
    lli m = (l+r+1)>>1;
        if((m*m)+m>=n)
            r = m;
        else 
            l = m; 
    }
    lli inv6 = mod_pow(6,mod-2,mod);
    lli diff = n-((l*l)+l);

    lli x = (l*(l+1));
    x%=mod;
    x*= ((2ll)*l+1);
    x%=mod;
    x*= inv6;
    x%=mod;
    x*=2;
    x%=mod;
    lli y = diff*r;
    y%=mod;
    lli ans = x+y;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}