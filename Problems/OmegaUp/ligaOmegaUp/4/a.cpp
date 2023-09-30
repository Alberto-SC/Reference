#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    lli sum =accumulate(nums.begin(),nums.end(),0ll);
    lli ans = 0;
    for(int i = 0;i<n;i++){
        sum-=nums[i];
        ans+= nums[i]*sum;
    }
    cout<<ans<<endl;
    return 0;
}