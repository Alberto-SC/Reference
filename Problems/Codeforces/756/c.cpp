#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        if(nums.back()!=n && nums[0]!= n){
            cout<<-1<<endl;
        }
        else{
            reverse(nums.begin(),nums.end());
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}