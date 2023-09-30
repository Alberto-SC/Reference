#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,k,H;
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>H;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int diff = abs(nums[i]-H);

            if(diff%k==0 and diff/k<m && diff)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}