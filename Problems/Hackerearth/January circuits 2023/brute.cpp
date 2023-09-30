#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            int mn = 1e9;
            int ans = 0;
            for(int i = l;i<=r;i++){
                mn = min(mn,nums[i]);
                ans+=mn;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}