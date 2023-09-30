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
        sort(nums.begin(),nums.end());
        int a = 0,b = 0;
        b+=nums.back();
        a+=nums[0]+nums[1];
        int l = 2,r = n-2;
        bool flag = false;
        while(l<r){
            if(b>a)flag = true;
            a+=nums[l++];
            b+=nums[r--]; 
        }
        if(b>a)flag = true;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}   