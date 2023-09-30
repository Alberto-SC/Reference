#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans,t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        cout<<abs(nums[n]-nums[n-1])<<endl;
    }
    return 0;
}