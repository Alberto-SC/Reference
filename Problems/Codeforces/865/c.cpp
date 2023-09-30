#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


bool solve(int l,int r,int mn,int mx,vector<int> &v){
    if(mn>mx)return false;
    if(l == r && v[l]>=mn && v[r]<=mx)return true;
    if(l == r-1){
        int diff = min(mn-v[l],0ll);
        v[l]+=diff;
        v[r]+=diff;
        if(v[l]>=mn && v[r]<=mx && v[l]<=v[r])return true;

        diff = min(v[r]-mx,0ll);
        v[l]-=diff;
        v[r]-=diff;
        if(v[l]>=mn && v[r]<=mx && v[l]<=v[r])return true;
        return false;
    }

    int diff = mn-v[l];
    v[l]+=diff;
    v[l+1]+=diff;

    diff = v[r]-mx;

    v[r]-=diff;
    v[r-1]-=diff;

    if(v[l]>=mn && v[r]<=mx)return solve(l+1,r-1,v[l],v[r],v);
    return false;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int l = 0,r = n-1;
        vector<int> ans(n);
        for(auto &c:ans)cin>>c;
        if(solve(l,r,-1e12,1e12,ans))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}