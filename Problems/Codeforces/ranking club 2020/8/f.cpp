#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.rbegin(),nums.rend());
    int ans = 0;
    for(int i = 0;i<k;i++)
        ans+=nums[i];
    cout<<ans<<endl;
    return 0;
}