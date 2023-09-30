#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int x,y, z = 2;
    int cont = 25;
    for(int i= 2;i<=26;i++){
        cout<<"? "<<1<<" "<<i<<endl;
        cin>>x;
        cout<<"? "<<i<<" "<<1<<endl;
        cin>>y;
        if(x ==-1)return cout<<"! "<<i-1<<endl,0;
        if(x != y)return cout<<"! "<<x+y<<endl,0;
    }
    return 0;
}