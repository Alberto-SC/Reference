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
    int T = 1,n,p;
    int inv2 = mod_pow(2,mod-2);
    while(T--){
        cin>>n>>p;
        vector<int> s2(n+1);
        vector<int> s(n+1);

        s2[1] = inv2;
        s[1] = inv2;
        
        for(int i = 2;i<=n;i++){
            int invp = mod_pow(mod_pow(p,i-1),mod-2);
            s[i] = s[i-1] +(invp*inv2);
            s[i]%=mod;
            
            int x = inv2*mod_pow(invp,2);
            x%=mod;
            x+= s2[i-1];
            x%=mod;
            x+=invp*s[i-1];
            x%=mod;
            s2[i] = x;
        }

        for(int i = 1;i<=n;i++){
            cout<<s2[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}