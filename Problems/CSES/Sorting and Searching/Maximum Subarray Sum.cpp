#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = -1e18, mn = 0,ac = 0;
        for(int i = 0;i<n;i++){
            ac+=nums[i];
            mx = max(mx,ac-mn);
            mn = min(mn,ac);
        }
        cout<<mx<<endl;
    }
    return 0;
}