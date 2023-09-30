#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,h;
    cin>>t;
    while(t--){
        cin>>n>>h;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        int s = nums[0]+nums[1];
        int x = h/s;
        int ans = x*2;
        if(h%s==0)ans+= 0;
        else if(h-(s*x)<=nums[0])ans+=1;
        else ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}  
