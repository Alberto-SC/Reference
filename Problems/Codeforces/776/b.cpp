#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,l,r,a;
    cin>>t;
    while(t--){
        cin>>l>>r>>a;
        int x = r/a;
        int m = r%a;
        int ans = x+m;
        if(r-(m+1)>=l){
            int z = r-(m+1);
            ans = max(ans,(z/a)+(z%a));
        }
        cout<<ans<<endl;
    }
}   