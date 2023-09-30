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
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int res = 0;
            for(int j = 1;j*j<=i;j++){
                if(i%j == 0){
                    res+=mp[j];
                    if(j*j!=i)res+=mp[i/j];
                }
            }
            ans = max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}