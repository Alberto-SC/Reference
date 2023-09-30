#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli mod_mult(lli a,lli b,lli m){
    lli x = 0;
    while(b){
        if(b&1)x = (x+a)%m;
        a = (a<<1)%m;
        b>>=1;
    }
    return x;
}

lli mod_pow(lli a,lli b,lli m){
    lli x = 1;
    while(b){
        if(b&1) x = mod_mult(x,a,m);
        a = mod_mult(a,a,m);
        b>>=1;
    }
    return x;
}

int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<mod_pow(a,b,10)<<endl;
    }
    return 0;
}