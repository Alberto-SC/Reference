#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,a,b;
    while(T--){
        cin>>a>>b;
        if(b == a*2 || b == (a*2)+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}