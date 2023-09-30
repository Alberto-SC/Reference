#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int lcm(int a,int b){
    return a*(b/__gcd(a,b));
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;

        int ans = (n/a) + (n/b) + (n/c);
        
        ans -= n/(a*b/__gcd(a,b));
        ans -= n/(a*c/__gcd(a,c));
        ans -= n/(b*c/__gcd(b,c));
        if(lcm(a,b)<=n)
            ans += n/lcm(lcm(a,b),c);
        
        cout<<ans<<endl;
    }
    return 0;
}