#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld long double

signed main(){__
    int n,h,l,c;
    while(cin>>n>>h>>c>>l){
        int H = n*h,C = n*c;
        ld x = sqrt((H*H)+(C*C));
        cout<<fixed<<setprecision(4);
        cout<<(x*l)/10000.0<<endl;
    }

}   