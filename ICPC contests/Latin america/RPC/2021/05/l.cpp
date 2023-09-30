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
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        int ans = 1e18;
        for(int i = 0;i<n;i++){
            if(s-nums[i]== nums[i])ans = nums[i];
        }
        if(ans==1e18)cout<<"BAD"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}  
