#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int mn = *min_element(nums.begin(),nums.end());
    int mx = *max_element(nums.begin(),nums.end());
    map<int,int> mp;
    for(int i = 0;i<n;i++)
        mp[nums[i]]++;
    if(mp[mn]>2)return cout<<"Impossible"<<endl,0;
    if(mp[mn] ==1 && mx != mn*2)return cout<<"Impossible"<<endl,0;
    if(mp[mn] == 2 && mx != (mn*2)-1)return cout<<"Impossible"<<endl,0;
    bool flag = true;
    for(int i = mn+1;i<mx;i++)
        if(mp[i]<2)flag = false;
    

    if(flag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
