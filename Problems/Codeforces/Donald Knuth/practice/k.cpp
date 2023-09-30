#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

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
	int t= 1,n;
    while(t--){
        cin>>n;
        map<int,int> mp;
        int l = 0,r = (int)sqrt(n)+1;
        while(l+1<r){
            int m = (l+r)>>1;
            if((m*m)+m<=n)
                l = m;
            else 
                r = m;
        }
            int inv6 = mod_pow(6,mod-2),N = (l*l)+l,diff = n-N;
        int ans =  (l*(l+1))%mod;
        int y = ((2*l)+1)%mod;
        (ans*=y)%=mod;
        (ans*=inv6)%=mod;
        (ans*=2)%=mod;
        y = ((diff%mod)*((l+1)%mod))%mod;
        (ans+=y)%=mod;
        cout<<ans<<endl;
    }
    return 0;
}  
// 1 2
// 2 6
// 3 12
// 4 20
// 5 30
// 6 42