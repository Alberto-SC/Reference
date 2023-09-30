#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
    int n;
    ld u;
    cin>>n>>u;
    vector<ld> nums(n);
    ld ans =-1;
    for(auto &c:nums)cin>>c;
    for(int i = 1;i<n-1;i++){
        int index = lower_bound(nums.begin()+i+1,nums.end(),nums[i-1]+u)-nums.begin();
        if(nums[index] == nums[i-1]+u)ans = max((nums[index]-nums[i])/(nums[index]-nums[i-1]),ans);
        else 
            index--;
        if(index == i)continue;
        else {
            ans = max((nums[index]-nums[i])/ (nums[index]-nums[i-1]),ans);
        }
    }
    cout<<fixed<<setprecision(12);
    cout<<ans<<endl;
    return 0;
}