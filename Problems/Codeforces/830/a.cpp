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
        int gcd = 0;
        for(auto &c:nums)cin>>c,gcd=__gcd(gcd,c);
        if(gcd == 1){
            cout<<0<<endl;
            continue;
        }
        int ans = n;
        for(int i =0;i<n;i++){
            vector<int> nw = nums;
            nw[i] = __gcd(i+1,nums[i]);
            gcd = 0;
            for(int j = 0;j<n;j++){
                gcd = __gcd(gcd,nw[j]);
            }

            if(gcd == 1){
                ans = min(ans,(n-(i+1))+1);
            }
        }
        if(ans >3 && n>=3){
            ans = 3;
        }
        cout<<ans<<endl;
    }
    return 0;
}