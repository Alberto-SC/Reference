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
        vector<int> mx(n),mn(n);
        mx[0] = nums[0];
        for(int i = 1;i<n;i++)
            mx[i] = max(nums[i],mx[i-1]);
        mn[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--)
            mn[i] = min(nums[i],mn[i+1]);
        bool flag = false;
        for(int i = 1;i<n;i++)
            if(mn[i]<mx[i-1])flag = true;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}