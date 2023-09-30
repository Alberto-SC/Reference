#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    a = n/100;
    n-= a*100;
    b = n/20;
    n-= b*20;
    c = n/10;
    n-= c*10;
    d = n/5;
    n-= d*5;
    cout<<a+b+c+d+n<<endl;
    return 0;
}