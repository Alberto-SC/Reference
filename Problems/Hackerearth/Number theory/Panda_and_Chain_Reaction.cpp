#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 1e6+3;

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
    int t = 1,n,x;
    cin>>t;
    vector<int> facts(mod);
    facts[0] = 1;
    for(int i = 1;i<mod;i++)
        facts[i] = (facts[i-1]*i)%mod;
    while(t--){
        cin>>n>>x;
        if(n>= mod)cout<<0<<endl;
        else cout<<(facts[n]*x)%mod<<endl;
    }
    return 0;
}   