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
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && (nums[i]&1) == (nums[j]&1)){
                j++;
            }
            ans +=j-i-1;
            i = j;
        }
        cout<<ans<<endl;
    }
    return 0;
}