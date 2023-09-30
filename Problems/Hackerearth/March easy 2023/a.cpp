#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    vector<int> used(n);
    int ans = 0;
    int idx = 1;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){ 
        if(used[i])continue;
        while(idx<n && (nums[idx]-nums[i])<k)idx++;
        if(idx>=n)break;
        ans++;
        used[idx] = true;
        idx++;
    }
    cout<<ans<<endl;
    return 0;
}

