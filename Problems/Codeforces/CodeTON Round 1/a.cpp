#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cout<<(min_element(nums.begin(),nums.end())-nums.begin())+1<<" "<<(max_element(nums.begin(),nums.end())-nums.begin())+1<<endl;
    }
}   