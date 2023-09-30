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
        vector<int> dp(100007);
        for(int i = 0;i<n;i++){
            dp[nums[i]]= 1;
            int mx = 0;
            for(int j = 2;j*j<=nums[i];j++){
                if(nums[i]%j== 0){
                    mx = max(mx,dp[j]);
                    mx = max(mx,dp[nums[i]/j]);
                }
            }
            dp[nums[i]]+=mx;
            for(int j = 2;j*j<=nums[i];j++){
                if(nums[i]%j== 0){
                    dp[j] = dp[nums[i]];
                    dp[nums[i]/j] = dp[nums[i]];
                }
            }
        }   

        int ans = 0;
        cout<<endl;
        for(int i = 0;i<n;i++)
            ans = max(ans,dp[nums[i]]);
        cout<<ans<<endl;
    }
    return 0;
}  
