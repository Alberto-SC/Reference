#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n),b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;

        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());

        int ans = 1;
        for(int i = 0;i<n;i++){
            int c = upper_bound(a.begin(),a.end(),b[i])-a.begin();
            c = n-c;
            ans = (ans*(max(0ll,c-i)))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}