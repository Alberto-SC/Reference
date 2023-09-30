#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,z;
    cin>>t;
    while(t--){
        cin>>n>>z;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,nums[i]|z);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
