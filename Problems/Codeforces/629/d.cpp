#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        nums.push_back(nums[i]);
        vector<int> ans = nums;
        for(int i = 1;i<n;i++){
            if(nums[i]>=3 &&nums[i]!= num[i-1] && nums[i+1]!= nums[i]){
                if(nums[i]== 3 && nums[i-1]!= nums[i+1])continue;
            }
            else if(nums[i]!= nums[i+1]);
        }
    }
    return 0;
}
