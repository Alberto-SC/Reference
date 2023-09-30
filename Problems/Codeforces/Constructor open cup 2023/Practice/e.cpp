
#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,vector<int>> pos;
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        int ans = n;
        for(int i = 0;i<n;i++){
            int last = nums[i];
            int lastidx = i;
            int cont = 1;
            while(1){
                int nxt = last*2;
                int idx = lower_bound(pos[nxt].begin(),pos[nxt].end(),lastidx)-pos[nxt].begin();

                if(idx == pos[nxt].size())break;
                last = nxt;
                lastidx = pos[nxt][idx];

                cont++;
            }

            ans = min(ans,n-cont);
        }
        cout<<ans<<endl;

    }
    return 0;
}
