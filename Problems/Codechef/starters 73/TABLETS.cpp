#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        x*=3;
        if(y>=x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}