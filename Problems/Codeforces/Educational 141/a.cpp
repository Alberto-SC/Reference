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
        sort(nums.rbegin(),nums.rend());
        if(nums[1]==nums[0])swap(nums[1],nums.back());
        bool flag = true;
        int s = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==s)flag = false;
            s+=nums[i];
        }
        if(flag){
            cout<<"YES"<<endl;
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}