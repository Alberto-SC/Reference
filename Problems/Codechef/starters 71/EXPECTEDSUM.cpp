#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;
int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n,A,B;
    cin>>T;
    while(T--){
        cin>>A>>B;
        n = A+B;
        int M = (n+1)/2;
        int ans = A*M;
        ans%=mod;
        ans*=mod_pow(n,mod-2);
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}