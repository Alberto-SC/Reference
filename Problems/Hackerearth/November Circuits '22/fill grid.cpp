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
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> comb = {1,4,6,4,1};
        int ans = 0;
        for(int i = 0;i<5;i++){
            int x = mod_pow(comb[i],n-3)*mod_pow(2,12);
            x%=mod;
            ans+=x;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}