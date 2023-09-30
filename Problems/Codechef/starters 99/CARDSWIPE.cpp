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
        map<int,int> seen;
        
        int c = 0, ans = 0;
        for(int i = 0;i<n;i++){
          if(seen.count(nums[i])) c--,seen.erase(nums[i]);
          else c++,seen[nums[i]] = 1;
          ans = max(ans,c);
        }
        cout<<ans<<endl;

    }
    return 0;
}