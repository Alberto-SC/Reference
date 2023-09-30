#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int ans =0;
        for(auto &c:nums)cin>>c,ans|=c;
        cout<<ans<<endl;
    }
    return 0;
}