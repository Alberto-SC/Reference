#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b,c;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        int x = a-1;
        int y = abs(c-b)+(c-1);
        if(x<y)cout<<1<<endl;
        else if(y<x)cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}