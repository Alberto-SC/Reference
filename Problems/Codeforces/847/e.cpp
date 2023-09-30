#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,x;
    cin>>T;
    while(T--){
        cin>>x;
        int b = x/2;
        if(x&b || x&1)
            cout<<-1<<endl;
        else cout<<(2*x)-b<<" "<<b<<endl;
    }
    return 0;
}