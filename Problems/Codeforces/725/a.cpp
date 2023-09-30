#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        int ans = 0,a,b;
        for(int i = 0;i<n;i++){
            if(nums[i]==mn)
                a = i;
            else if(nums[i]==mx)
                b = i;
        }
        ans = min({max(a+1,b+1),max(n-a,n-b),min(a,b)+1+(n-max(a,b))});
        cout<<ans<<endl;
    }
    return 0;
}