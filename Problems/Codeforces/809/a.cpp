#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        string ans = string(m+1,'B');

        for(int i = 0;i<n;i++){
            int a = nums[i];
            int b = m+1-nums[i];

            if((a<b && ans[a]== 'B') || ans[b]== 'A')
                ans[a] = 'A';
            else 
                ans[b] = 'A';
        }

        for(int i = 1;i<=m;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}