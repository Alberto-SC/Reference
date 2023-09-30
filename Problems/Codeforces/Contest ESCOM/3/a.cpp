#include <bits/stdc++.h>
using namespace std;
const double PI =  acos(-1);
int main(){
    int t;
    double a,b,d,sides,R,r,ACM,sol;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf",&a,&b,&d);
        sides=d/(sqrt(2));
        r= sides/2.0;
        R=d/2.0;
        sol=PI*(2.0*(r*r)-(R*R))+sides * sides;
        printf("%.7f\n",sol);
    }
    return 0;
}