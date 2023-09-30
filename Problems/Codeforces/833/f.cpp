#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>n>>m;
    int N = 200001;


    vector<pair<int,int>> v(n); 
    int sum= 0;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        sum+=v[i].first;
        int x = v[i].second-v[i].first;
        mp[x]++;
    }
    int INF = 1e9;
    vector<int> dp(N);
    dp[sum] = 0;

    for (const auto &[w, k] : mp) {
        vector<int> ndp = dp;
        if(w ==0)continue;
        if(w>0){
            for (int i = -w+1j; i < w; i++) {   
                deque<pair<int, int>> ww;
                for (int j = i, mul = 0; j <= N; j += w, mul++) {
                    if(!ndp.count(j))ndp[j] = INF;
                    if(!dp.count(j))dp[j] = INF;
                    while (!ww.empty() && ww.front().second < mul - k)
                        ww.pop_front();

                    if (!ww.empty()){
                        if(!ndp.count(j))ndp[j] = ww.front().first+mul;
                        else
                            ndp[j] = min(ndp[j], ww.front().first + mul);
                    }  

                    while (!ww.empty() && dp.count(j) && ww.back().first >= dp[j] - mul)
                        ww.pop_back();
                    
                    ww.emplace_back(dp[j] - mul, mul);
                }
            }
        }
        else{
            for (int i = (-w)-1; i > w; i--) {   
                deque<pair<int, int>> ww;
                for (int j = i, mul = 0; j >= -N; j += w, mul++) {
                    if(!ndp.count(j))ndp[j] = INF;
                    if(!dp.count(j))dp[j] = INF;
                    while (!ww.empty() && ww.front().second < mul - k)
                        ww.pop_front();

                    if (!ww.empty()) {
                        if(!ndp.count(j))ndp[j] = ww.front().first+mul;
                        else
                            ndp[j] = min(ndp[j], ww.front().first + mul);
                    }   
                    while (!ww.empty() && dp.count(j) && ww.back().first >= dp[j] - mul)
                        ww.pop_back();
                    
                    ww.emplace_back(dp[j] - mul, mul);
                }
            }
        }
        swap(ndp, dp);
    }

    for(int i = 0;i<=m;i++){
        int need = i-sum;
        // cout<<sum<<" "<<need<<endl;
        if(i==sum)cout<<0<<endl;
        else if(!dp.count(need)|| dp[need]==INF)cout<<-1<<endl;
        else cout<<dp[need]<<endl;
    }
    
    return 0;
}