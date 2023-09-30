#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    sort(nums.begin(),nums.end());
    set<int> numss;
    for(int i = 0;i<n;i++)
        numss.insert(nums[i]);
    if(numss.size()!= n)return cout<<0<<endl,0;
    vector<int> nums2(n);
    for(int i = 0;i<n;i++)
        nums2[i] = nums[i]&x;
    set<int> numss2;
    for(int i = 0;i<n;i++)
        numss2.insert(nums2[i]);
    if(numss2.size()== n)return cout<<-1<<endl,0;
    for(int i = 0;i<n;i++){
        int index = lower_bound(nums.begin(),nums.end(),nums[i]&x)-nums.begin();
        if(nums[index] == (nums[i]&x) && index != i)return cout<<1<<endl,0;
    }
    return cout<<2<<endl,0;
}