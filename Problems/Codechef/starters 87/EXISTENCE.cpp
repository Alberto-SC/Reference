#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;

        if(((4*x)-(4*y))%x == 0){
            int d = ((4*x)-(4*y))/x;
            if((x*x)%d == 0){
                if(y == (x*x)/d)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;

    }
    return 0;
}