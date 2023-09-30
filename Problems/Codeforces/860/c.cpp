#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

int LCM(int a,int b){
    return a*b/__gcd(a,b);
}

int32_t main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
    
        int idx = 0;
        int ans = 0;
        while(idx<n){
            int r = idx;          
            int gcd =0;
            int lcm = 1;

            while(r<n){
                gcd = __gcd(gcd,nums[r].first*nums[r].second);
                lcm = LCM(lcm,nums[r].second);

                if(gcd%lcm)break;
                r++;
            }
            idx = r; 
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
