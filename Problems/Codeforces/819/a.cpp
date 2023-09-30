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
        int mn = 1e9,mx = -1e9;
        for(auto &c:nums)cin>>c,mn = min(mn,c),mx = max(mx,c);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i==0)
                ans = max(ans,nums[n-1]-nums[i]);
            else
                ans = max(ans,nums[i-1]-nums[i]);
        }

        if(nums[0]== mn || nums.back()==mx)cout<<mx-mn<<endl;
        else cout<<max({mx-nums[0],nums.back()-mn,ans})<<endl;
    }
    return 0;
}