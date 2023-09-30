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
        for(auto &c:nums)cin>>c;
        int ans = 1e18;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int res = 0;
                for(int k = 0;k<n;k++){
                    int x = nums[k]-nums[i];
                    int y = nums[k]-nums[j];
                    if(x*x<y*y)res+=x*x;
                    else res+=y*y;
                }
                ans = min(ans,res);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
