#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int gcd = 0;
        for(auto &c:nums)cin>>c,gcd = __gcd(c,gcd);
        int ans = 0;
        for(int d = 1;d*d<=gcd;d++){
            if(gcd%d ==0){
                ans++;
                if(gcd/d != d)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}