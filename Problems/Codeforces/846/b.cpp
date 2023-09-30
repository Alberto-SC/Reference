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
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        int s = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            s+=nums[i];
            ans = max(ans,__gcd(s,sum-s));
        }
        cout<<ans<<endl;
    }
    return 0;
}