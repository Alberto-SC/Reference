#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main(){__
    int t= 1,n,l;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<vector<int>> mx(150001);
        for(int i = 0;i<n;i++){
            mx[nums[i]].push_back(i);
        }
        int ans = -1;
        for(int i = 0;i<=150000;i++){
            if(mx[i].size()<2)continue;
            for(int j = 0;j<mx[i].size()-1;j++){
                ans = max(ans,mx[i][j]+ n-mx[i][j+1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
