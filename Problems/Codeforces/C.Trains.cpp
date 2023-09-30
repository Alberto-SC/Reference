#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int gcd = __gcd(a,b);
    a/=gcd;
    b/=gcd;
    if(abs(a-b) == 1 )return cout<<"Equal"<<endl,0;
    a<b?cout<<"Dasha"<<endl:cout<<"Masha"<<endl;
    return 0;
}