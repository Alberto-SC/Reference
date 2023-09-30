#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n+1);

        int sum = 0;
        for(int i= 1;i<=n;i++){
            cin>>nums[i];
            sum+=nums[i];
        }
        
        if(sum&1){
            cout<<-1<<endl;
            continue;
        }

        sum/=2;
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) 
            dp[i][0] = 0;

        
        for (int i = 1; i <=n; i++){
            for (int j = 1; j <= sum; j++){
                dp[i][j] = dp[i-1][j];
                if(dp[i][j]!=-1)continue;
                if(j >= nums[i] && dp[i-1][j-nums[i]]!=-1)
                    dp[i][j] = i;
            }
        }

        if(dp[n][sum]!=-1){         
            vector<int> l,r;

            while(sum){
                int id = dp[n][sum];
                l.push_back(id);
                sum-=nums[id];
            }

            set<int> stl(l.begin(),l.end());
            for(int i = 1;i<=n;i++){
                if(stl.count(i))continue;
                r.push_back(i);
            }

            int idxl = 0,idxr = 0;

            vector<pair<int,int>> ans;

            while(idxl<l.size() && idxr<r.size()){
                ans.push_back({l[idxl],r[idxr]});

                int mn = min(nums[l[idxl]],nums[r[idxr]]);

                nums[l[idxl]]-=mn;
                nums[r[idxr]]-=mn;
                if(nums[l[idxl]] == 0)idxl++;
                if(nums[r[idxr]] == 0)idxr++;
            }

            cout<<ans.size()<<endl;
            for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}