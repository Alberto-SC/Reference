#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
        int ans = 1000000007;
    if(k == 1){
        for(int i = 0;i<n;i++)ans = min(ans,nums[i]);
        return cout<<ans<<endl,0;
    }
    else{
        ans = -ans;
        for(int i = 0;i<n;i++)ans = max(ans,nums[i]);
        if(k == 2)return cout<<max(nums[0],nums[n-1])<<endl,0;
        return cout<<ans<<endl,0;
    }

    return 0;
}