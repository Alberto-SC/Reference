#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b,c,d;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        int l = max(a,c);
        int r = min(b,d);
        
        int ans = (b-a)+1;
        ans += (d-c)+1;
        if(l<=r){
            ans-=(r-l)+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}