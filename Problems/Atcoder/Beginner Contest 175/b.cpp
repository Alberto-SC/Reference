#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i]== nums[j])continue;
            for(int k = j+1;k<n;k++){ 
                if(nums[j]== nums[k] || nums[k]== nums[i])continue;
                vector<int> s;
                s.push_back(nums[i]);
                s.push_back(nums[j]);
                s.push_back(nums[k]);
                sort(s.begin(),s.end());
                if(s[0]+s[1]>s[2])ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}