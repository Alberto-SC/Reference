#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        cout<<max(0ll,sum-m)<<endl;
    }
    return 0;
}