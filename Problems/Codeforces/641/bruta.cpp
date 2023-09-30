#include <bits/stdc++.h>
using namespace std;
lli gcd(vector<lli> &nums){
    lli ans =0;
    for(lli &num:nums)ans =__gcd(ans,num);
    return ans;
}
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
int main(){
    int n;
    cin>>n;
    vector<lli> nums(n);
    vector<lli> n2;
    for(auto &c:nums)cin>>c;
    for(lli i = 0;i<n;i++){
        for(lli j = i+1;j<n;j++){
            n2.push_back(lcm(nums[i],nums[j]));
        }
    }
    cout<<gcd(n2);

    return 0;
}