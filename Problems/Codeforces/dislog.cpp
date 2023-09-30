#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int powmod(lli a, lli b, lli m) {
    lli res = 1;
    while (b > 0) {
        if (b & 1) {
            res = ((res%m) * (a%m)) % m;
        }
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}

lli dislog(lli a, lli b, lli m) {
    lli n = (lli) sqrt (m + .0) + 1;
    map<lli, lli> vals;
    for (lli p = n; p >= 1; --p)
        vals[powmod(a, p * n, m)] = p;
    for (lli q = 0; q <= n; ++q) {
        lli cur = (powmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            lli ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
int main(){
    lli a,b,m;
    cin>>a>>b>>m;
    lli dis = dislog(a,b,m);
    cout<<dis<<endl;
    cout<<powmod(2ll,dis,m)<<endl;
    return 0;
}