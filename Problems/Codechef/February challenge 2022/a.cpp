#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long double x = 0.143*n;
        long double y = x;
        for(int i = 1;i<n;i++)
            x*=y;
        cout<<fixed<<setprecision(0);
        cout<<round(x)<<endl;
    }
    return 0;
}