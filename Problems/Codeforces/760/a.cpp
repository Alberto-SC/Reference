#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        vector<int> nums(7);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        vector<int> a;
        a.push_back(nums[0]);
        a.push_back(nums[1]);
        if(nums[2]== nums[0]+nums[1])a.push_back(nums[3]);
        else a.push_back(nums[2]);
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }
    return 0;
}