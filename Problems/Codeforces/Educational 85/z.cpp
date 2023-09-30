#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
typedef long double ld;
using comp = complex<long double>;
int main(){
    comp a,b2,a2;
    ld ang1 = 2 * PI * 0/ 3;
    ld ang2 = (PI - 2 * PI * 0) / 3;
    a = comp(cosl(ang1), sinl(ang1));
    a2 = comp(cosl(ang2), sinl(ang2));
    ang1 = 2 * PI * 2 / 3;
    ang2 = (PI - 2 * PI * 2) / 3;
    b2 = comp(cosl(ang2),sinl(ang2));
    cout<<a<<endl;
    cout<<a2<<endl;
    cout<<b2<<endl;
    cout<<a*a2<<endl;
    cout<<a*b2<<endl;
    return 0;
}