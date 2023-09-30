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
        int one = 0;
        for(auto &c:nums)cin>>c,one+=c==1;

        int ans = one/2;

        int rem = n-one;
        if(one&1)rem++;
        ans+=rem;
        cout<<ans<<endl;

    }
    return 0;
}