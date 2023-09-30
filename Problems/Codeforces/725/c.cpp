#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,l,r;
    cin>>T;
    while(T--){
        cin>>n>>l>>r;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]>r)break;
            if(nums[i]>=l){
                int R = upper_bound(nums.begin()+i+1,nums.end(),r-nums[i])-nums.begin();
                ans+=R-(i+1);
            }
            else {
                int L = lower_bound(nums.begin()+i+1,nums.end(),l-nums[i])-nums.begin();
                int R = upper_bound(nums.begin()+i+1,nums.end(),r-nums[i])-nums.begin();
                ans+=R-L;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}