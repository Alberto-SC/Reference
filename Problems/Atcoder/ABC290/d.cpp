#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n,d,k;
        cin>>n>>d>>k;
        
        int gcd = __gcd(n,d);

        int cycle = n/gcd;

        int need = (k+(cycle-1))/cycle;
         
        int start = need-1;
        int steps = (k-1)%cycle;
        cout<<start+((steps*d)%n)<<endl;
    }
    return 0;
}
