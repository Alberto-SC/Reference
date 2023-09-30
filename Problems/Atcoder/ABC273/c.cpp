#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

// TODO(alberto-sc)


signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        vector<int> v = nums;
        sort( v.begin(), v.end() );
        v.erase(unique( v.begin(), v.end()),v.end());
        reverse(v.begin(),v.end());
        vector<int> ans(n);
        for(int i = 0;i<v.size();i++){
            ans[i] = mp[v[i]];
        }
        
        for(auto c:ans)cout<<c<<endl;
    }
    return 0;
}
