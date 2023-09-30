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
        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int> pos0[31];
        vector<int> pos1[31];

        for(int bit = 30;bit>=0;bit--){
            for(int i = 0;i<(2*n);i++){
                if((nums[i]>>bit)&1)pos1[bit].push_back(i);
                else pos0[bit].push_back(i);
            }
        }


        int ans = 0;
        for(int x= 0;x<n;x++){

            int l = x,r = (x+n)-1;

            int res = 0;
            // cout<<l<<" "<<r<<endl;
            int L = x,R = (x+n)-1;
            for(int bit = 30;bit>=0;bit--){
                
                int last1 = lower_bound(pos1[bit].begin(),pos1[bit].end(),L)-pos1[bit].begin();
                int nxt0 =  lower_bound(pos0[bit].begin(),pos0[bit].end(),r)-pos0[bit].begin();

                if(last1 != pos1[bit].size() && pos1[bit][last1]<=l && nxt0 != pos0[bit].size() && pos0[bit][nxt0] <=R){
                    res|=1<<bit;
                    continue;
                }

                int nxt1 = lower_bound(pos1[bit].begin(),pos1[bit].end(),L)-pos1[bit].begin();
                nxt0 = lower_bound(pos0[bit].begin(),pos0[bit].end(),L)-pos0[bit].begin();

                if(nxt1== pos1[bit].size() || nxt0 == pos0[bit].size() || pos1[bit][nxt1]>R || pos0[bit][nxt0] >R)
                    continue;


                int last0 = lower_bound(pos0[bit].begin(),pos0[bit].end(),R)-pos0[bit].begin();
                
                if(last0 == pos0[bit].size() && last0)
                    last0--;

                if(pos0[bit][last0]>R)
                    last0--;

                // cout<<l<<" "<<r<<" "<<pos1[bit][nxt1]<<" "<<pos0[bit][last0]<<endl;
                int nl = max(pos1[bit][nxt1],l);
                int nr = min(pos0[bit][last0],r);
                if(nl>=nr)continue;
            
                l = nl;
                r = nr;
                res|=1<<bit;
            }
            // cout<<res<<endl;
            // cout<<endl;
            ans = max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}