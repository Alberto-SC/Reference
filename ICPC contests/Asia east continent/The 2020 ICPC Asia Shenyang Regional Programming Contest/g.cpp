#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        int ans = 0;
        for(int i= 0;i<k;i++){
            ans+=nums[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}