#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n>>u>>v;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool block = true;
        int ans = 1e9+7;
        for(int i = 0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])>1)
                ans = 0;
            else if(abs(nums[i]-nums[i+1]==1))
                ans = min({ans,u,v});
            else 
                ans = min({ans,u+v,2*v});
        }
        cout<<ans<<endl;    
    }
    return 0;
}  
