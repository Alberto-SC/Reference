#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        int yp,lp,ys,ls;
        cin>>yp>>lp>>ys>>ls;

        int ans = yp*ys;
        ans = min(ans,(yp+abs(yp-lp))*ls);
        ans = min(ans,(abs(yp-lp)*ys)+(lp*ls));
        cout<<ans<<endl;
    }
    return 0;
}

