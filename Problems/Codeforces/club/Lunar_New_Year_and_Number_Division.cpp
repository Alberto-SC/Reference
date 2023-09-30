#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x: nums)cin>>x;
    sort(nums.begin(),nums.end());
    long long ans =0;
    for(int i = 0;i<n/2;i++)
        ans+= (nums[i]+nums[(n-1)-i])*(nums[i]+nums[(n-1)-i]);
    cout<<ans<<endl;
    return 0;
}