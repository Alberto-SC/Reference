#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
signed main(){__
    ld w,h;
    cin>>w>>h;
    ld x = w*w+h*h;
    x = sqrt(x);
    ld ans = w+h-x;
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;

    return 0;
}  
