#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 1e9;
    vector<int> pref(n);
    pref[0] = (nums[0]+1)/2;
    for(int i = 0;i<n-1;i++){
        int mn = min(nums[i],nums[i+1]);
        int mx = max(nums[i],nums[i+1]);
        if(2*mn<=mx)
            ans = min(ans,(mx+1)/2);
        else
            ans = min(ans,(nums[i]+nums[i+1]+2)/3);
    }

    for(int i = 1;i<n;i++){
        pref[i] = min(pref[i-1],(nums[i]+1)/2);
        if(i>1)ans = min(ans,pref[i-2]+(nums[i]+1)/2);
    }
    for(int i = 1;i<n-1;i++){
        ans = min(ans,(nums[i-1]+nums[i+1]+1)/2);
    }

    cout<<ans<<endl;
    return 0;
}