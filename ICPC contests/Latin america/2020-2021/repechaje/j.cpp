#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double

signed main(){__
    int T = 1,n,C,F,B,S;
    cin>>T;
    while(T--){
        cin>>C>>F>>B>>S;
        int lcm = 12/__gcd(__gcd(F,B),12ll);
        ld ans = (S*12.0)/(C*lcm*1.0);
        cout<<ans<<endl;
        cout<<lcm<<endl;
        cout<<ceil(ans)*lcm<<endl;
    }
    return 0;
}