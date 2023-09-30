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
        int ans = 0;

        for(int i = 0;i<n;){
            int l = i;
            while(l<n && (nums[l]!=0) == (nums[i]!=0)){
                l++;
            }
            if(nums[i]!= 0)ans++;
            i = l;
        }
        cout<<min(ans,2ll)<<endl;
    }
    return 0;
}  


