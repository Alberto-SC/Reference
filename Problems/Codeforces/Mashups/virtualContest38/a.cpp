#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i =1;i<n;i++){
            int mx = max(nums[i-1]+1,nums[i]);
            ans+=mx-nums[i];
            nums[i] = mx;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
