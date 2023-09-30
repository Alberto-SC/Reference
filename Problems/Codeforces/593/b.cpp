#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;

lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
int main(){__
	lli t= 1,n,m;
    while(t--){
        cin>>n>>m;
        lli ans = bin_pow(2,m)-1;
        ans = bin_pow(ans,n);
        cout<<ans<<endl;
    }
    return 0;
}  

