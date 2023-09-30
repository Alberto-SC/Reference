#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<long double> nums(n);
        long double sum = 0;
        for(auto &c:nums)cin>>c,sum+=c*c*c;

        long double ans = cbrt(sum);
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}