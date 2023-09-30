#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,w,h;
    cin>>T;
    while(T--){
        cin>>n>>w>>h;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        int L = -1e18,R = 1e18;
        for(int i = 0;i<n;i++){
            int l = (b[i]-h) -(a[i]-w);
            int r = (b[i]+h) -(a[i]+w);

            if(l>r)swap(l,r);
            // cout<<l<<" "<<r<<endl;
            L = max(l,L);
            R = min(r,R);
        }
        if(L<=R)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
