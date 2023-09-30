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

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 0;i<n;){
            int j = i+1;
            while(j<n && nums[j]>nums[j-1] == nums[i+1]>nums[i]){
                j++;
            }
            if(j-1 == i)break;
            ans.push_back(nums[j-1]);
            i = j-1;
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}