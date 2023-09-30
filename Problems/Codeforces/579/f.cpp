#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,r;
    while(T--){
        cin>>n>>r;
        vector<pair<int,int>> nums(n);
        vector<pair<int,int>> pos,neg;
        for(auto &[a,b]:nums){
            cin>>a>>b;
            if(b<0)
                neg.push_back({a,b});
            else
                pos.push_back({a,b});
        }
        int total = 0;
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.first+a.second>b.first+b.second;
        });
        for(int i = 0;i<pos.size();i++){
            if(r>=pos[i].first){
                total++;
                r+=pos[i].second;
            }
        }   
        int N = neg.size();
        vector<vector<int>> dp(N+1,vector<int>(r+1,0));
        dp[0][r] = total;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<=r;j++){
                if(j>=neg[i].first && j+neg[i].second>=0){
                    dp[i+1][j+neg[i].second] = max(dp[i+1][j+neg[i].second],1+dp[i][j]);
                }
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            }
        }   
        int ans = 0;
        for(int i = 0;i<=r;i++)
            ans = max(ans,dp[N][i]);
        if(ans ==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}