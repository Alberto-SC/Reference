#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld long double

using  namespace std;
signed main(){
    ld v0, v1, v2, t, d, x0=0, x1=1, x2=0;
    cin>>d>>v0>>v1>>v2>>t;
    cout<<fixed<<setprecision(10);
    ld temp= 0.0;
    ld tl = 0,tr = t;
    int times = 64;
    while(times--){
        ld m = (tl+tr)/2;
        if(isless(v2*m,1+(v1*m))){
            tl = m;
        }
        else tr = m;
    }

    cout<<tr<<endl;

    if(islessequal(t,tr)){
        return cout<<min(v2*t,d)<<endl,0;
    }
    if(isgreater(v2*tr,d)){
        ld t1 = d/v2;
        ld x22 = v2*t1;
        ld need = d-x22;
        tr = t1+(need/v2);
    }
    x0 += v0*tr;
    x1 += v1*tr;
    x2 += v2*tr;
    t-=tr;
    tl = 0,tr = t;
    times = 64;
    while(times--){
        ld m = (tl+tr)/2;
        if(isless(x0+(v0*m),x2-(v2*m))){
            tl = m;
        }
        else tr = m;
    }
    if(islessequal(t,tr)){
        return cout<<x2-(v2*t)<<endl,0;
    }
    x0+=v0*tr;
    x1+=v1*tr;
    x2-=v2*tr;
    t-=tr;
    x2 =min(d,x2+v2*t);
    cout<<x2<<endl;
    return 0;
}