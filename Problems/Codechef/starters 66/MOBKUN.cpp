#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,k,x;
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x;
        int y = (n*k)+m;
        int M = n+m;
        if((x%y) >(y-M) || x%y==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}