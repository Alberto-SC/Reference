#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 0;
    for(int i = 1;i<n;i++){
        if(nums[i]>=nums[i-1])continue;
        ans += nums[i-1]-nums[i];
        nums[i] = nums[i-1];
    }
    cout<<ans<<endl;
    return 0;
}