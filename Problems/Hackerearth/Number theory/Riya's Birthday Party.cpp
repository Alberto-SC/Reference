#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 1e9+7;

int modPow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int t,n;
    cin>>t;
    int inv2 = modPow(2,mod-2);
    while(t--){
        cin>>n;
        n--;
        int x = n%mod;
        x = (x*(x+1))%mod;
        (x*=inv2)%mod;
        (x*=4)%=mod;
        (x+=n+1)%=mod;
        cout<<x<<endl;
    }
}   