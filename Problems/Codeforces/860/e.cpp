#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

int32_t main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans;
        vector<int> dp(n);
        vector<int> sz(n);
        dp[n-1] = nums[n-1]!=0;
        sz[n-1] = 1;

        for(int i = n-2;i>=0;i--){
            int res = 0;
            int need = dp[i+1];
    
            cout<<nums[i]<<" "<<sz[i+1]<<" "<<need<<endl;
            if(nums[i]== sz[i+1]){
                res = need;               
            }
            else if(need == 0)res = 1;
            else res = 2;

            if(i+nums[i]+1>=n){
                if(i+nums[i]+1== n)dp[i] = 0,sz[i] = 1;
                else
                    dp[i] = 1,sz[i] = 1;
            }
            else dp[i] = dp[i+nums[i]+1],sz[i] = sz[i+nums[i]+1]+1;

            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
