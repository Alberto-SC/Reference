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
        m--;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = n;
        int msk;
        for(int mask = 0;mask<(1<<n);mask++){
            vector<int> nw = nums;
            for(int i = 0;i<n;i++){
                if((mask>>i)&1)nw[i]*=-1;
            }

            vector<int> pref(n);
            pref[0] = nw[0];
            int mn = pref[0];
            for(int i = 1;i<n;i++){
                pref[i] = pref[i-1]+nw[i];
                mn = min(mn,pref[i]);
            }
            if(pref[m]==mn){
                int res = __builtin_popcount(mask);
                if(res<ans){
                    msk = mask;
                }
                ans = min(ans,(int)__builtin_popcount(mask));
            }
        }
        bitset<16> bs(msk);
        // cout<<bs<<endl;
        cout<<ans<<endl;
    }
    return 0;
}