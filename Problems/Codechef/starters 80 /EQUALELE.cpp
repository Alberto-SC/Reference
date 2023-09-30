#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int mx = 0;
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++,mx = max(mx,mp[c]);
        cout<<n-mx<<endl;
    }
    return 0;
}
