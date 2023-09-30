#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        vector<int> nums(3);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        cout<<nums[1]<<endl;
    }
    return 0;
}