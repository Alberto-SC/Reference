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
        map<int,int> mp;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++)
            mp[nums[i]]++;
        for(int i= 0;i<mp.size();i++)
            cout<<mp.size()<<" ";
        for(int i = mp.size();i<n;i++)
            cout<<mp.size()+((i-mp.size())+1)<<" ";    
        cout<<endl;
    }
}