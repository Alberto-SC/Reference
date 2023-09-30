#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

const int mod = 1e9+7;
signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        map<int,int> mp;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,mp[c]++;
    
        int mul = 1;
        int ans = 0;
        for(int i =1 ;i<=n;i++){
            if(mp[i]==0)break;
            (mul*=mp[i])%=mod;
            
            (ans+=mul)%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;


}
