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

        vector<int> pos[n+1];
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }

        for(int i = 1;i<=n;i++){
            if(pos[i].size()==0){
                cout<<0<<" ";
                continue;
            }
            vector<int> dp(pos[i].size());
            dp[0] = 1;
            int mxim = -1;
            int mxpr = -1;
            int best = 1;
            if(pos[i][0]&1)mxim = 1;
            else mxpr = 1;
            for(int j = 1;j<pos[i].size();j++){
            
                if(pos[i][j-1] == pos[i][j]-1)
                    dp[j] = dp[j-1]+1;

                if(pos[i][j]&1 && mxpr != -1)
                    dp[j] = max(dp[j],mxpr+1);
            
                else if(pos[i][j]%2 == 0 && mxim != -1)
                    dp[j] = max(dp[j],mxim+1);


                if (pos[i][j]&1)
                    mxim = max(mxim,dp[j]);
                else 
                    mxpr = max(mxpr,dp[j]);

                best = max(best,dp[j]);
            }
            cout<<best<<" ";
        }
        cout<<endl;
    }
    return 0;
}