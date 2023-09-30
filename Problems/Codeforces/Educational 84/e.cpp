#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 998244353;
int main(){__
    int t = 1,n,m,k,x,y;
    cin>>n;
    vector<lli> p10;
    p10.push_back(1);
    p10.push_back(10);
    for(int i = 0;i<n;i++)
        p10.push_back((p10.back()*10)%mod);
    
    lli ans = 0;
    for(int i = 1;i<n-1;i++){
        ans = 0;
        lli x = (n-i)-1;
        lli y = x*9*9;
        y%=mod;
        (y*=p10[(n-i)-2])%=mod;
        (y*=10)%=mod;
        (ans+=y)%=mod;

        lli z = 9;
        (z*=p10[(n-i)-1])%=mod;
        (z*=2)%=mod;
        (z*=10)%=mod;
        (ans+=z)%=mod;
        // cout<<z<<endl;
        cout<<ans<<" ";
    }
    if(n>1)
        cout<<2*10*9<<" ";
    cout<<10<<endl;
}

