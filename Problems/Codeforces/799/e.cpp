#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t,n,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ac(n);
        ac[0] = nums[0];
        for(int i = 1;i<n;i++)
            ac[i] = ac[i-1]+nums[i];
        int ans = 1e9;
        int x = 0;
        for(int i = 0;i<n;i++){
            int l = i-1, r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                if(ac[m]-x>=s+1)
                    r = m;
                else 
                    l = m;
            }
            if(r <n){
                r--;
                cout<<i<<" "<<r<<" "<<i+(n-(r+1))<<endl;
                ans = min(ans,i+(n-(r+1)));
            }
            x+=nums[i];
        }
        cout<<ans<<endl;
    }
    return 0;
} 