#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        for(int i = 0;i<n;i++)
            mp[nums[i]]++;
        int ans = 0;
        for(auto c:mp){
            if(c.second&1)ans++;
        }
        if((n+ans)%4)ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}
