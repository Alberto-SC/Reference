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
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(nums[i]==copy[n-1])
                ans[i] = nums[i]-copy[n-2];
            else 
                ans[i] = nums[i]-copy[n-1];
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}