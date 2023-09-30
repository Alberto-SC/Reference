#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int mn = 1e9;
        int ans = 0;
        for(auto &c:nums)cin>>c,mn = min(mn,c);
        for(auto c:nums)if(c>mn)ans++;
        cout<<ans<<endl;
        
    }
    return 0;
}

 
