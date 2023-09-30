#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b,c,x,y;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>x>>y;
        int needa = max(0ll,x-a);
        int needb = max(0ll,y-b);
        if(c>=needa+needb)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}