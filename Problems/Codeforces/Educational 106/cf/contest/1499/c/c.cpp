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
        vector<int> a,b;
        for(int i = 0;i<n;i++){
            if(i&1)a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        int res= 1e18;
        int ans =0,s =0;
        for(int i = 0;i<a.size();i++){
            res = min(res,s+((n-i)*a[i]));
            s += a[i];
        }
        ans +=res;
        res = 1e18,s =0;
        for(int i = 0;i<b.size();i++){
            res = min(res,s+((n-i)*b[i]));
            s += b[i];
        }
        ans+=res;
        cout<<ans<<endl;
    }
    return 0;
}  
