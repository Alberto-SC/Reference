#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(m);
        for(auto &c:nums)cin>>c;

        sort(nums.begin(),nums.end());

        int ans = nums[0];
        for(int i = 1;i<m;i++){
              int x = n-ans;
              if(x<nums[i])
                ans = nums[i]-x;
              else if(x>=nums[i])
                ans = 0;
        }

        cout<<ans<<endl;

    }
    return 0;
}