#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    vector<int> nums(3);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    bool flag = false;
    do{
        if(nums[1]-nums[0] ==nums[2]-nums[1])flag = true;
    }while(next_permutation(nums.begin(),nums.end()));
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}  
