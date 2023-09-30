#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n <= 2){
            cout<<0<<endl;
            continue;
        }
        int p = (n+1)/2;
        int e = n/2;
        int ans;
        if(n%2 == 0)
            ans = (p+1)+((e-2)*2);
        else
            ans = p+((e-1)*2);
        cout<<ans<<endl;
    }
    return 0;
}