#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,y;
    cin>>T;
    while(T--){
        cin>>x>>y;
        if(y%x)cout<<"0 0"<<endl;
        else cout<<1<<" "<<y/x<<endl;
    }
    return 0;
}