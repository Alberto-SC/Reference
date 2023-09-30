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
        int ans = 0;
        int i = -1,j = 0;
        map<int,int> mp;
        for(j=0;j<n;j++) {
            mp[nums[j]]++;
            if(mp[nums[j]]>=2) {
                i++;
                while(nums[i] != nums[j]){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                ans = ans + (j-i);
            }
            else
                ans = ans + (j-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
