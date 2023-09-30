#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 998244353;
lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mo  d;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
  
int main(){__
	int n;
    cin>>n;
    lli DP[n+2];
    DP[0] = 1;
    DP[1] = 1;
    lli aci = 1;
    lli acp = 1;
    for(int i = 2;i<=n;i++){
        if(i&1)
            DP[i] = acp,(aci +=DP[i])%=mod;
        else    
            DP[i] = aci,(acp +=DP[i])%=mod;
        DP[i]%=mod;    
    }
    for(int i = 1;i<=n;i++)
        cout<<DP[i]<<" ";
    lli y = mod_pow(mod_pow(2,n),mod-2);  
    lli z = (DP[n]*y)%mod;
    cout<<z<<endl;
    return 0;
}  

