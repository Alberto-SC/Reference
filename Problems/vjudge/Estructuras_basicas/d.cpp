#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int ans = 0;
    cin>>n;
    vector<int> nums(n);
    for(auto &c: nums)cin>>c;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=ceil(log2(nums[n-1]+nums[n-2]));j++){
            int pw = pow(2,j);
            int search = pw-nums[i];
            // cout<<pw<<"  "<<search<<endl;
            if(search<1)continue;
            int index = lower_bound(nums.begin(),nums.end(),search)-nums.begin();
            int index2 = upper_bound(nums.begin(),nums.end(),search)-nums.begin();
            if(nums[index] == search && index!= i){ans+=(index2-index);}
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
