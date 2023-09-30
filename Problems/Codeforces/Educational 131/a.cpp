#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a+b+c+d == 4)cout<<2<<endl;
        else if(a+b+c+d >=1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}