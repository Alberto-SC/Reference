#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int mul(int a,int b){
    a%=mod;
    b%=mod;
    a*=b;
    a%=mod;
    return a;
}

int pow_mod(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int inv2 = pow_mod(2,mod-2);
        int inv6 = pow_mod(6,mod-2);
        int n3 = mul(n,mul(n,n));

        int x = mul(n3 ,mul( mul(n,n-1) ,inv2) );
        x = mul(x, mul(mul(mul(n-1,n) ,(2*n)-1),inv6));
        int ans = 0;
        ans+=x*10;
        ans%=mod;
        int y = x+ mul(mul(mul(n,n+1),inv2),n3);
        y%=mod;
        ans+= y*4;
        ans%=mod;
        int z1 = mul(mul(n+3,n+4),inv2)-(mul(mul(n+1,n),inv2));
        if(z1<0)z1+=mod;
        int z = x+ mul(z1,n3);
        z%=mod;
        ans+=z*2;
        ans%=mod;
        int z2 = mul(mul(n+1,n+2),inv2)-1;
        if(z2<0)z2+=mod;
        z = x+ mul(z2,n3);
        z%=mod;
        ans+=z*4;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}