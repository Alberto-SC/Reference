#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    vector<int> conb;
    vector<tuple<int, int,int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i] == nums[j])continue;
            for(int k = j+1;k<n;k++){
                if(nums[k]>nums[j])
                ans.push_back(make_tuple(nums[i],nums[j],nums[k]));
            }
            for(int x = 0;x<n;x++){
                if(x ==i || x == j)continue;
                for(int z = 0;z<n;z++){
                    if(z==i || z ==j || z == x)continue;
                    int a = nums[x]+nums[z];
                    // cout<<x<<" "<<z<<" "<<a<<endl;
                    if(a> nums[j])ans.push_back(make_tuple(nums[i],nums[j],a));
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    // for(auto c:ans)cout<<get<0>(c)<<" "<<get<1>(c)<<" "<<get<2>(c)<<endl;
    return 0;
}