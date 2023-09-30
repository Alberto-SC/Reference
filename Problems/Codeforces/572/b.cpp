#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());   
    for(int i =0;i<n;i++){
        if(1+1<n && nums[i+1]>nums[i]||(i-1>=0 && nums[i-1]>nums[i]))continue;
        else if(!i && nums[n-1]+nums[i+1]>nums[i])continue;
        else {
            if(i+1==n)
            swap(nums[i],nums[0]);
            else swap(nums[i],nums[i+1]);
        }
    }
    for(int i = n-1;i>=0;i--){
        if(i ==n-1 &&nums[i-1]+nums[0]>nums[i] || (i-1>=0 && nums[i-1]>nums[i]) )continue;
        else if(nums[i-1]+nums[i+1]>nums[i])continue;
        else {
            if(i-1<0)
            swap(nums[i],nums[n-1]);
            else swap(nums[i],nums[i-1]);
        }
    }
    for(auto a:nums)cout<<a<<" ";
    cout<<endl;
    for(int i =0;i<n;i++){
        if(i-1<0 && nums[i+1]+nums[n-1]<=nums[i]){cout<<"NO"<<endl;return 0; }
        if(i+1==n && nums[0]+nums[i-1]<=nums[i]){cout<<"NO"<<endl;return 0; }
    }
    for(int i = 0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}