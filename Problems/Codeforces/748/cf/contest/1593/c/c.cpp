#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(k);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int s = 0,ans = 0;
        for(int i = k-1;i>=0;i--){
            if(nums[i]<=s)break;
            s += n-nums[i];
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
