#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        int ans = 0;
        for(auto d:mp){
            ans = max(ans,d.second);
        }
        cout<<ans<<" "<<mp.size()<<endl;
    }
    return 0;
}  
