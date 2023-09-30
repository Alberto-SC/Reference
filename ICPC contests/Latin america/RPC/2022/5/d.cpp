#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld long double 
#define pi acos(-1)

ld volume(ld h,ld r,ld R){
    ld x =(r*r)+(r*R) +(R*R);
    return (pi*h*x)/3;
}   


signed main(){__
    ld r,R,h,m,H;
    cin>>r>>R>>h>>m>>H;
    ld vol = volume(h,r,R);
    ld D = (r*h)/(R-r);
    ld h2 = h+D;
    ld r2 = (R/h2) * (D+H);
    ld vol2 = volume(h-H,R,r2);
    ld x= ((vol-vol2)*m)/(vol2);
    cout<<fixed<<setprecision(10);
    cout<<x<<endl;
}   