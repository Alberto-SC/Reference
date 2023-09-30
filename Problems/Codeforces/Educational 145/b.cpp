#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    cin>>T;
    while(T--){
        cin>>n;

        int l = 0,r = 1e9+7;
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        while(l+1<r){
            int m = (l+r)>>1;
            if(((m+1)*(m+1))>=n)r = m;
            else l = m;
        }
        cout<<r<<endl;
    }
    return 0;
}
 
