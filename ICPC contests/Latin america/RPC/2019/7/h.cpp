#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
    double As,ps,r,pw;
    cin>>As>>ps>>r>>pw;
    double vs,vw;
    vs = As/ps;
    vw = (PI*r*r)/pw;
    if(vs>vw)cout<<"Slice of pizza"<<endl;
    else cout<<"Whole pizza"<<endl;

    return 0;
}