#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    for(int i = 0;i<n;i++);
    sort(nums.begin(),nums.end());
    int mn,negative= 0,zeros =0;
    for(int i = 0;i<n;i++){
        if(nums[i]<0)negative++,mn = nums[i];
        if(nums[i] == 0)zeros++;
    }
    long long ans = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]== 0)ans+=1;
        else if(nums[i] == 1)ans+=0;
        else if(nums[i]<0){
            if(abs(nums[i]) == 1)ans+=0;
            else 
                ans+=abs(nums[i])-1;
        }
        else ans+=nums[i]-1;
    }
    if(negative&1){
        if(zeros>0)ans+=0;
        else ans+=2;
        
    }cout<<ans<<endl;
    return 0;
}