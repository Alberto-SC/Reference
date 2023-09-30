#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i = 0;i<n;i+=2){
        ans+=nums[i+1]-nums[i];
    }
    cout<<ans<<endl;
    return 0;
}