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
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-1;i++){
            nums.back() = nums.back()*nums[i];
            nums[i] = 1;
        }
        int ans = nums.back()+(n-1);
        ans*=2022;
        cout<<ans<<endl;
    }
    return 0;
}