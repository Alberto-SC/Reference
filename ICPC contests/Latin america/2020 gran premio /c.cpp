#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        n++,m++;
        int x = (n*(n+1))/2;
        x%=mod;
        x*=m;
        x%=mod;
        cout<<x<<endl;
    }
    return 0;
}