#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b,p,q;
    while(t--){
        cin>>n>>a>>b>>p>>q;
        int lcm = a*b/__gcd(a,b);
        int c = n/lcm;
        int x = ((n/a)-c)*p;
        int y = ((n/b)-c)*q;
        cout<<x+y+((p>q)?c*p:c*q)<<endl; 
    }
    return 0;
}  
