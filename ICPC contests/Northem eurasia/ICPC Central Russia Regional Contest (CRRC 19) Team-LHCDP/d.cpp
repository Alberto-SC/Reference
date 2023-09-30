#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a);
        a*=a;
        b>>=1;
    }
    return x;
}

int main(){__
    lli a,b;
    cin>>a>>b;
    for(int i = 1;i<=100;i++){
        lli y = bin_pow(a,i);
        lli z = bin_pow(i,b);
        cout<<y<<" "<<z<<" "<<y-z<<endl;
    }
    return 0;
}  

