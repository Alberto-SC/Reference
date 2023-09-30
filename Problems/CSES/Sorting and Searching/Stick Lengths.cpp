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
        sort(nums.begin(),nums.end());
        int target = nums[n/2];
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans +=abs(nums[i]-target);
        }
        cout<<ans<<endl;
    }
    return 0;
}