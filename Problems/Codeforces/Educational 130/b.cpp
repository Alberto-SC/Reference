#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> ac(n);
    sort(nums.begin(),nums.end());

    ac[0] = nums[0];
    for(int i = 1;i<n;i++){
        ac[i] = ac[i-1]+nums[i];
    }


    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = ac[(n-x)+(y-1)];
        ans = ans-((n-x)>0?ac[n-x-1]:0);
        cout<<ans<<endl;
    }
    return 0;
}