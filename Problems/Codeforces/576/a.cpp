#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,y;
    while(T--){
        cin>>n>>x>>y;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int idx = -1;
        for(int i = 0;i<n;i++){
            int mn = 2e9;
            for(int j = i-1;j>=max(0ll,i-x);j--)
                mn = min(mn,nums[j]);
            for(int j = i+1;j<=min(n-1,i+y);j++)
                mn = min(mn,nums[j]);
            
            // cout<<mn<<endl;
            if(nums[i]<mn){
                idx = i;
                break;
            }
        }
        cout<<idx+1<<endl;
    }
    return 0;
}