#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define printP(A)for(auto c:A)cout<<"("<<c.fi<<","<<c.se<<")  ";cout<<endl;
const int maxy = 100007;
int main(){
    int n,x,y,mx = -1,c;
    cin>>n;
    pair<int,int> coords[maxy];
    for(int i = 0;i<n;i++){
        cin>>x>>y>>c;
        mx = max(mx,y);
        if(c == 1)
            coords[y].fi++;
        else 
            coords[y].se++;
    }
    int j,k;
    int ans = 0,pylons = 0;
    for(int i= 0;i<=mx;i++){
        ans += min(pylons, coords[i].se);
        pylons -= coords[i].se;
        if(pylons<0)pylons = 0;
        else 
            ans += min(pylons, coords[i].fi);
        coords[i].fi -= pylons;
        if(coords[i].fi < 0)pylons = coords[i].se;
        else 
            pylons = coords[i].se + coords[i].fi;
    }   

    cout<<ans<<endl;
    return 0;
}