#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    int ans = 0;
    for(auto &c:nums)cin>>c;
    int s = 0;
    nums.push_back(0);
    for(int i = 0;i<=n;i++){
        s+=nums[i];
        if(!nums[i]){
            ans+=s/2;
            s = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}