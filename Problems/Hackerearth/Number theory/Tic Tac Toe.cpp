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
    int inv6 = modPow(6,mod-2);
    while(t--){
        cin>>n;
        int mx = (n-1)*(2*(n-1)+1)%mod;
        (mx*=(n))%=mod;
        (mx*=inv6)%=mod;
        int y = (n*(n-1))/2;

        int res = y%n;
        int x = y/n;
        int z = x+1;
        int mn = ((x*x)%mod)*((n-res)%mod);
        mn%=mod;
        mn+= (((y*y)%mod)*(res%mod))%mod;
        cout<<mn<<" "<<mx<<endl;
    }
}   
