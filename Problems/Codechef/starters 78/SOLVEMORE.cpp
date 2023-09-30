#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({a[i]+b[i],a[i]});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        vector<int> ac(n);
        ac[0] = v[0].first;
        for(int i = 1;i<n;i++)
            ac[i] = v[i].first+ac[i-1];

        for(int i = 0;i<n;i++){
            int nk = k-v[i].second;
            if(nk<0) continue;
            
            int l = -1,r = i;
            while(l+1<r){
                int m = (l+r)>>1;
                if(ac[m]<=nk)l = m;
                else r = m;
            }

            if(l<i-1){
                ans = max(ans,l+2);
                continue;
            }
            nk-= (i-1)>=0?ac[i-1]:0;

            int lr = i,rr = n;
            while(lr+1<rr){
                int m = (lr+rr)>>1;
                if((ac[m]-ac[i])<=nk)lr = m;
                else rr = m;
            }
            ans = max(ans,i+1+(lr-i));
        }

        cout<<ans<<endl;
    }
}
