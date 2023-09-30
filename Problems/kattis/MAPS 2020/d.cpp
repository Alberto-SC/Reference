#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main(){
    int t,n;
    long double l,d,g;
    cin>>t;
    cout<<fixed<<setprecision(14);
    while(t--){
        cin>>n>>l>>d>>g;
        long double grados = 360/n;
        long double radianes = (grados*pi)/180.0; 
        long double apotema =  l/(2*tan(radianes/2));
        long double area = (n*l*apotema)/2.0;
        cout<<area<<endl; b
        long double ans = l*g*d*n;
        ans+= area;
        long double circle = pi*(d*g*d*g);
        ans+=circle;
        
        cout<<ans<<endl;
    }
    return 0;

}