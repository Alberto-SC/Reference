#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q,l,r;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n),prefS(n);
        int x = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            x^=nums[i];
            sum+=nums[i];
            pref[i] = x;
            prefS[i] = sum;
        }

        map<int,vector<int>> posI;
        map<int,vector<int>> posP;
        for(int i = 0;i<n;i++){
            if(i&1)
                posI[pref[i]].push_back(i);
            else 
                posP[pref[i]].push_back(i);
        } 


        while(q--){
            cin>>l>>r;
            l--,r--;
            int len = (r-l)+1;
            int sum = prefS[r]-(l?prefS[l-1]:0);
            int xr = pref[r]^(l?pref[l-1]:0);
            if(sum ==0)cout<<0<<endl;
            else if(len==2|| xr)cout<<-1<<endl;
            else if(len&1)cout<<1<<endl;
            else if(len%2 ==0 && !nums[l]|| !nums[r])cout<<1<<endl;
            else{
                if(l&1){
                    int s = l?pref[l-1]:0;
                    auto idx = upper_bound(posI[s].begin(),posI[s].end(),l)-posI[s].begin();
                    if(idx >= posI[s].size() || posI[s][idx]>=r)cout<<-1<<endl;
                    else cout<<2<<endl;
                }
                else{
                    int s= l?pref[l-1]:0;
                    auto idx = upper_bound(posP[s].begin(),posP[s].end(),l)-posP[s].begin();
                    if(idx >= posP[s].size() ||posP[s][idx]>=r)cout<<-1<<endl;
                    else cout<<2<<endl;
                }
            }
        }
    }
    return 0;
}