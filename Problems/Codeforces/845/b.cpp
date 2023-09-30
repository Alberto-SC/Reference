#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
signed main(){__
    int T = 1,n;
    cin>>T;
    vector<int> fact(100007);
    fact[0] = 1;
    for(int i = 1;i<=100000;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=mod;
    }

    while(T--){
        cin>>n;
        n+=2;
        int ans = (n-2)*(n-3);
        ans%=mod;
        ans*=(fact[n-2]);
        ans%=mod;
        cout<<ans<<endl;

    }
    return 0;
}