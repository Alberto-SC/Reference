#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int mx = *max_element(nums.begin(),nums.end());
    if(mx == m)return cout<<"YES"<<endl,0;
    if(mx< m && k>0)return cout<<"YES"<<endl,0;
    else if(mx< m && k == 0)return cout<<"NO"<<endl,0;
    sort(nums.begin(),nums.end());
    int ind = lower_bound(nums.begin(),nums.end(),m)-nums.begin();
    if((n-ind)<=k)return cout<<"YES"<<endl,0;
    cout<<"NO"<<endl;
    return 0;
}