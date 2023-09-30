#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<ld> nums(n);
        for(auto &c:nums)cin>>c;
        ld ans =0;
        sort(nums.rbegin(),nums.rend());
        ld f = 0.5;
        for(int i = 0;i<n;i++){
            ans+=nums[i]*f;
            f*=0.5;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
