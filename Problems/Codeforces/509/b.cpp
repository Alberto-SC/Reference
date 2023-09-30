#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli a,b,x,y;
    cin>>a>>b>>x>>y;
    lli gcd = __gcd(x,y);
    x/=gcd;
    y/=gcd;
    if(a<x || b<y)cout<<0<<endl;
    else{
        lli amax = a/x;
        lli bmax = b/y;
        cout<<min(amax,bmax)<<endl;
    }
    return 0;

}