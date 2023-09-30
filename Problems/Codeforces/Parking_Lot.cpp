#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli  binpow(lli  a,  lli b) {
    lli  res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    lli sobran = n-2;
    lli pos = n-1;
    lli ans = 0;
    if(pos >=0)ans += 4*3*3*binpow(4,n-4)*(n-3);
    ans += 4*3*binpow(4,sobran-1)*2;        
    cout<<ans<<endl;
    return 0;
}