#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int last = 0;
        vector<int> pos(n+1);
        for(int i = 0;i<n;i++){
            pos[nums[i]] = i;
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(pos[i]<last){
                i = i+k-1;
                ans++;
                last = n+1;
            }
            else last = pos[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}