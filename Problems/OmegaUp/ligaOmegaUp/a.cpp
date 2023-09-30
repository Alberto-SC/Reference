#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    cin>>a>>b; 
    int ind1 = lower_bound(nums.begin(),nums.end(),a)-nums.begin();
    int ind2 = lower_bound(nums.begin(),nums.end(),b)-nums.begin();
    if(nums[ind2] != b)ind2--;
    cout<<(ind2-ind1)+1<<endl;
    
    return 0;
}