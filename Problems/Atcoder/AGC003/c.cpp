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
    vector<int> copy = nums;
    sort(nums.begin(),nums.end());
    map<int,int>mp;
    for(int i = 0;i<n;i++)
        mp[nums[i]] =i;
    
    for(int i = 0;i<n;i++)
        if((mp[copy[i]]&1) != (i&1))ans++;
    cout<<ans/2<<endl;
    return 0;
}