#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int mod_pow(int a,int b){
    int x= 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n;
    int inv6 = mod_pow(6,mod-2);
    int inv2 = mod_pow(2,mod-2);
    cin>>T;
    while(T--){
        cin>>n;
        int x = ((((n*(n+1)%mod)*((2*n)+1))%mod) * inv6)%mod;
        int y = (((n*(n-1))%mod)*inv2)%mod;
        n--;
        int z = ((((n*(n+1)%mod)*((2*n)+1))%mod) * inv6)%mod;
        int ans = x+y+z;
        ans%=mod;
        ans*=2022;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}