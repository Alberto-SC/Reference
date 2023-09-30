#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 


signed main(){__
    int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        int res = 1;
        vector<int> dp(30);
        vector<bool> valid(1000007,true);
        vector<int> _all;
        for(int i = 2;i<=n;i++){
            if(!valid[i])continue;
            _all.push_back(i);
            if(i*i<=n){
                int x = i;
                while(x<n){
                    x*=i;
                    if(x>n)break;
                    valid[x] = false;
                }
            }
        }
        int mx = 0;
        int x = 1;
        while(1){
            x*=2;
            if(x>n)break;
            mx++;
        }
        vector<bool> used(21*m);
        int ans = 0;
        for(int i = 1;i<=mx;i++){
            for(int j = 1;j<=m;j++){
                if(!used[i*j])ans++;
                used[i*j] = true;
            }
            dp[i]=ans;
        }

        for(auto c:_all){
            int mx = 0;
            int x = 1;
            while(1){
                x*=c;
                if(x>n)break;
                mx++;
            }
            res+=dp[mx];
        }
        cout<<res<<endl;
    }
}   