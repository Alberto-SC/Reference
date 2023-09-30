#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        for(int i = 0;i<n/2;i++){
            ans[(n-1)-(2*i)] = nums[(n-1)-i];
            ans[(n-1)-(2*i)-1] = nums[i];
        }
        if(n&1)ans[0] = nums[n/2];
        for(auto c:ans)cout<<c<<" ";
    }
    return 0;
}