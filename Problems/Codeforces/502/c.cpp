#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i+=2)
        nums[i] = i+1;
    for(int i = 1;i<n;i+=2)
        nums[i] = n&1?(n-1)-(i-1):n-(i-1);
    swap(nums[0],nums[n/2]);
    for(auto c:nums)cout<<c<<" ";
    cout<<endl;
    return 0;
}