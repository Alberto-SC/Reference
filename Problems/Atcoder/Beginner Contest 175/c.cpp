#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli x,k,d;
    cin>>x>>k>>d;
    if(d> abs(x)){
        if(k&1)cout<<abs(x-d)<<endl;
        else cout<<abs(x)<<endl;
    }
    else {
        lli y = x/d;
        if(k>=y){
            x-= (y*d);
            k-=y;
            if(k&1)cout<<abs(x-d)<<endl;
            else cout<<abs(x)<<endl;
        }
        else cout<<abs(x-(k*d));

    }
    return 0;
}