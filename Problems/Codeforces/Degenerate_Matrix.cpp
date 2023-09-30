#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
int main(){
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    double det = (a*d)-(b*c);
    cout<<fixed<<setprecision(10);
    if(!det)return cout<<0<<endl,0;
    double ans;
    if(a+b+c+d!=0) ans=fabs(det/(a+b+c+d));
    if(a+d-b-c!=0) ans=min(ans,fabs(det/(a+d-b-c)));
    if(b+d-a-c!=0) ans=min(ans,fabs(det/(b+d-a-c)));
    if(c+d-a-b!=0) ans=min(ans,fabs(det/(c+d-a-b)));
    printf("%.10lf\n",abs(ans));
    return 0;
}