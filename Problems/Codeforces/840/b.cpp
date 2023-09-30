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
        vector<int> h(n),p(n);
        for(auto &c:h)cin>>c;
        for(auto &c:p)cin>>c;
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            v[i] = {p[i],h[i]};
        }
        sort(v.begin(),v.end());
        int ac = 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            v[i].second-=ac;
            if(v[i].second<=0)continue;
            if(i)k-=v[i].first;
            int p = k/v[i].first;
            if(k%v[i].first==0)p--;
            int z = v[i].second-(k*(p+1)-(v[i].first*((p*(p+1))/2)));
            if(z>0){
                flag = false;
                break;
            }   
            else {
                int l = -1,r = p;
                while(l+1<r){
                    int m = (l+r)>>1;
                    int z = v[i].second-(k*(m+1)-(v[i].first*((m*(m+1))/2)));
                    if(z>0)l = m;
                    else r = m;
                }
                ac+=(k*(r+1)-(v[i].first*((r*(r+1))/2)));
                k-=v[i].first*r;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}