#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> nxt;
        for(int i = n-1;i>=0;i--)
            if(nums[i]>1)nxt.push_back(i);

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans++;
            if(q == 0){
                int nx = nxt.back();
                int len = nx-nxt;
            }
            if(nums[i]>q){
                q--;
            }
            if(nums[i]>1)nxt.pop_back();            
        }
        cout<<ans<<endl;

    }
    return 0;
}