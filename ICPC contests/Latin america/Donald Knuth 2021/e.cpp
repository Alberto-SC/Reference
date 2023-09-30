#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long 
signed main(){__
    int n;
    cin>>n;
    int p2 = 0,x = n,y = n+1;
    while(x%2==0){
        p2++;
        x/=2;
    }
    while(y%2==0){
        p2++;
        y/=2;
    }
    p2+=n-2;
    int gcd = min(n,p2);
    cout<<x*y*(1ll<<(p2-gcd))<<"/"<<(1<<(n-gcd))<<endl;
    return 0;
}  
