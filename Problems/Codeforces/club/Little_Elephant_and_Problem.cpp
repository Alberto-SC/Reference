#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto x:nums)cin>>x;
    vector<int> copy= nums;
    sort(copy.begin(),copy.end());
    int diff = 0;
    for(int i = 0;i<n;i++)
        if(nums[i]!=copy[i])diff++;
    if(diff == 2 || diff==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}