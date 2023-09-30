#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]<nums[i-1])ans++,i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
