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
        vector<int> nums(n);
        int ans = 0;
        for(auto &c:nums)cin>>c,ans+=(c&1);
        cout<<ans<<endl;
    }
    return 0;
}