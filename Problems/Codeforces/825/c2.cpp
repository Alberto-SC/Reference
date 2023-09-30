#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l = 0,r = 0;
        int ans = 0;
        vector<int> lim;
        vector<int> limL;
        vector<int> L(n+1);
        while(l<n){
            while(r<n && nums[r]>=((r-l)+1)){
                r++;
            }
            lim.push_back(r);
            L[r] = l;
            limL.push_back(l);
            if(r ==n){
                int L = r-l;
                ans+=(L * (L+1) )/2;
                break;
            }
            while(l<r && nums[r]<((r-l)+1)){
                ans+=r-l;
                l++;
            }
        }
        int q;
        cin>>q;
        while(q--){
            int p,nw;
            cin>>p>>nw;
            p--;
            int nxt = *upper_bound(lim.begin(),lim.end(),p);
            int z = *lower_bound(lim.begin(),lim.end(),p);
            int last = 0;
            if(z==p) {
                last = lower_bound(limL.begin(),limL.end(),L[p])-limL.begin();
                if(last)last = limL[last-1];
                else last = 0;
                if(nw>nums[p])
                    cout<<ans+(L[p]-last)<<endl;
                else k
            }   
            else{

                int L = nxt-p;
                int x = abs(min(p+1,nums[p])-min(p+1,nw));
                if(nw>nums[p])cout<<ans+(x*L)<<endl;
                else cout<<ans-(x*L)<<endl;
            }
        }
    }
    return 0;
}