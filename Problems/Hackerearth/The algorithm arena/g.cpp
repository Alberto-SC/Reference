#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;    
    vector<int> pref(n);
    vector<int> suf(n);
    pref[0] = nums[0];
    suf[n-1] = nums[n-1];

    for(int i = 1;i<n;i++){
        pref[i] = max(pref[i-1],nums[i]);
    }
    for(int i = n-2;i>=0;i--){
        suf[i] = max(suf[i+1],nums[i]);
    }
    int ans = 0;
    for(int i = 1;i<n-1;i++){
        ans+=max(0ll,min(pref[i],suf[i])-nums[i]);

    }
    cout<<ans<<endl;
    
}


