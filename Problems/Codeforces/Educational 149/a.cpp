#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x,k;
    cin>>T;
    while(T--){
        cin>>x>>k;
        if(x%k)
          cout<<1<<endl<<x<<endl;
        else
          cout<<2<<endl<<x-1<<" "<<1<<endl;
    }
    return 0;
}