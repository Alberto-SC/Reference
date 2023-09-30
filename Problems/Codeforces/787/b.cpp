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
        int ans = 0;
        for(int i = n-2;i>=0;i--){
            while(nums[i]>=nums[i+1] && ans<=1000){
                nums[i]/=2;
                ans++;
            }
        }
        if(ans>=1000)cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}