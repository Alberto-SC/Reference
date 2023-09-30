#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    cin>>T;
    while(T--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mxdiff = x*2;
        int mn = nums[0],mx = nums[0];
        int ans = 0;
        for(int i = 1;i<n;i++){
            mx = max(nums[i],mx);
            mn = min(nums[i],mn);
            if(mx-mn>mxdiff){
                ans++;
                mn = nums[i];
                mx = nums[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}