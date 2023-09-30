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
        for(auto &c:nums)cin>>c;
        if(n>=4)cout<<(*max_element(nums.begin(),nums.end())*n)<<endl;
        else if(n==1)cout<<nums[0]<<endl;
        else if(n==2)
            cout<<max(nums[0]+nums[1],2*(max(nums[0],nums[1])-min(nums[0],nums[1])))<<endl;
        else{
            int mx = max({nums[0],nums[1],nums[2]});
            int sum = nums[0]+nums[1]+nums[2];
            int ans = 0;
            if(nums[0]==mx || nums[2] == mx)ans = mx*3;
            ans = max(sum,3*nums[0]);
            ans = max(ans,3*nums[2]);
            ans = max(ans,3*abs(nums[0]-nums[2]));
            ans = max(ans,3*abs(nums[0]-nums[1]));
            ans = max(ans,3*abs(nums[1]-nums[2]));
            cout<<ans<<endl;
        }

    }
    return 0;
}