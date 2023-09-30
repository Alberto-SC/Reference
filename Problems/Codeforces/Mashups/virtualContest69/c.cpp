#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans  = 1e16;
        for(int i = 0;i<2*n;i++){ 
            for(int k = 0;k<2*n;k++){ 
                vector<int> to_use;
                for(int j = 0;j<2*n;j++){ 
                    if(j == i || j == k)continue;
                    to_use.push_back(nums[j]);
                }
                int res = 0;
                for(int j = 0;j<to_use.size()-1;j+=2){
                    res+=abs(to_use[j]-to_use[j+1]);
                }
                ans = min(ans,res);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
