#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int ans = (m*(m-1))/2;
        ans+=m*((n*(n+1))/2);
        cout<<ans<<endl;
    }
    return 0;
}