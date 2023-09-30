#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

const int mod = 1e9+7;

int mow_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T,n,m;
    cin>>T;
    int inv2 = mow_pow(2,mod-2);
    while(T--){
        int k;
        cin>>n>>m>>k;
        int N = n*m;
        int sum = ((N%mod)*((N+1)%mod))*inv2;
    
        int SC = 0;
        int SR = 0;
        int SCI = 0;
        int SRI = 0;

        int q,x,v;
        for(int i = 0;i<k;i++){
            cin>>q>>x>>v;
            if(q == 0){
                int y= x-1;
                (y*=m)%=mod;
                (y*=SC)%=mod;
                (y+=SCI)%=mod;
                (y*=v);
                (sum+=y)%=mod;
                SR+=v;
                SR+=v*x;
            }
            else{
                int y = x;
                (y*=x)%=mod;
                (y*=SR)%=mod;
                (y+=(n*SRI)%mod)%=mod;
                (y*=v-1);
                (sum+=y)%=mod;
                SC+=v;
                SCI+=v*x;
            }
            
        }
        cout<<sum<<endl;
    }
    return 0;
}
