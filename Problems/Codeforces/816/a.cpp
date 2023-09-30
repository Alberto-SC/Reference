#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int x = (n+m)-2;
        if(n<=m){
            x+=n;
        }
        else{
            x+=m;
        }
        if(n==1 && m==1)x = 0;
        cout<<x<<endl;

    }
    return 0;
}