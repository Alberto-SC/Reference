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
        sort(nums.rbegin(),nums.rend());
        int sum = 0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
          sum+=nums[i];
          ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());

        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}