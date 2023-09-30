#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__    
    int t,n,k;
    cin>>t;
    vector<int> mn(1007,1000);
    mn[1] = 0; 
    for(int i = 1;i<=1000;i++){
        for(int j = 1;j <=i;j++){
            if(i+(i/j)<= 1000)
                mn[i+(i/j)] = min(mn[i+(i/j)],mn[i]+1);
        }
    }
    
    while(t--){
        cin>>n>>k;
        vector<int> b(n);  
        vector<int> c(n);  
        for(auto &x:b)cin>>x;
        for(auto &x:c)cin>>x;
        
        vector<pair<int,int>>W(n);
        for(int i = 0;i<n;i++){
            W[i].first = mn[b[i]];
            W[i].second = c[i];
        }
        int K = min(k,13*n);
        vector<int> dp(K+1);
        for (int i = 0;i<n;i++) {
            for (int w = K; w >= 0; w--) {
                if (W[i].first <= w)
                    dp[w] = max(dp[w],dp[w -W[i].first] + W[i].second);
            }
        }
        cout<<dp[K]<<endl;
    }

}