#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    map<int,int> mp;
    for(int i  = 0;i<n;i++){
        mp[nums[i]]++;
    }
    int ans = 0;
    for(auto c:mp){
        if(c.first< c.second)ans+= abs(c.second-c.first);
        else if(c.first>c.second)ans+=c.second;
    }
    cout<<ans<<endl;
    return 0;
}