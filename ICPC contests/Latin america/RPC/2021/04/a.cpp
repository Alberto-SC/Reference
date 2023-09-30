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
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<n;){
            int j = i+1;
            while(j<n &&nums[j]==nums[j-1]+1){
                j++;
            }     
            ans+=nums[i];  
            i = j;    
        }
        cout<<ans<<endl;
    }
    return 0;
}  
