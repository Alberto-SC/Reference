#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,x,y,d;
    cin>>T;
    while(T--){
        cin>>n>>m>>x>>y>>d;
        if(x+d>=n && x-d<=1)
            cout<<-1<<endl; 
        else if(y+d>=m  && y-d<=1)
            cout<<-1<<endl;
        else if(x+d>=n && y+d>=m)cout<<-1<<endl;
        else if(x-d<=1 && y-d<=1)cout<<-1<<endl;
        else cout<<n+m-2<<endl;
    }
    return 0;
}