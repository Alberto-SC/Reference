#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main(){
    long double d,h,v,e;
    cin>>d>>h>>v>>e;
    long double s = v/(pi*(d*d/4.0));
    if(isgreater(e,s))
       return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    long double ans = h/(s-e);
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
       
    return 0;
}