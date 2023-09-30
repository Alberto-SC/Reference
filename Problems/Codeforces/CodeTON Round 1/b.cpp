#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool flag = false;
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            if(mp.count(nums[i]-k)|| mp.count(nums[i]+k))flag = true;
            mp[nums[i]];
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}   