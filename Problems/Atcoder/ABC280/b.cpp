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
        vector<int> ans(n);
        ans[0] = nums[0];
        int ac = nums[0];
        for(int i = 1;i<n;i++){
            ans[i] = nums[i]-ac;
            ac+=ans[i];
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}