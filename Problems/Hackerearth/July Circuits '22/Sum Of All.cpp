#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int powMod(int a,int b){
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
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        int x = 0;
        for(int i = 0;i<n;i++){
            int d = s[i]-'0';
            int l = (n-1)-i;
            int ten = powMod(10,l);
            (x+= (ten*d)%mod)%=mod;
            int y = powMod(2,i);
            ((y*=d)%=mod);
            y*=powMod(11,l);
            (ans+=y)%=mod;
        }
        ans-=x;
        if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}  
