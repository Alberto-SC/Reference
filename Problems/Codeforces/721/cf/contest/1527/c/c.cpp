#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto c:mp){
            int k = c.second.size();
            if(k==1)continue;
            vector<int> ac = {c.second[0]};
            for(int i = 1;i<k;i++)
                ac.push_back(ac.back()+c.second[i]);
            for(int i = 0;i<k-1;i++){
                int sz = k-(i+1);
                int x = c.second[i]+1;
                int y = (sz*n)-(ac.back()-ac[i]);
                ans+=x*y;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}  
