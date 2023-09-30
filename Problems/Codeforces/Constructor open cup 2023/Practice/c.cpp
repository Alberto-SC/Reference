
#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;


        int ans = 3;
        if(y1 == y2 || y2 == y3 || y1 == y3)ans--;
        if(x1 == x2 || x2 == x3 || x1 == x3)ans--;
        
        cout<<ans<<endl;
    }
    return 0;
}
