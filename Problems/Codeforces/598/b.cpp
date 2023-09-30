#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<bool> used(n,false);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            int j;
            for(j = 0;j<n;j++){
                if(nums[j] ==i+1)
                  break;  
            }
            for(int k = j;j>0;j--){
                if(!used[j] && nums[j]<nums[j-1])used[j] = true,swap(nums[j],nums[j-1]);
                else break;
            }
        }
        for(int i = 0;i<n-1;i++){
            if(!used[i] && nums[i]>nums[i+1])swap(nums[i],nums[i+1]);
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}