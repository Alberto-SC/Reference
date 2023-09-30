#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        
        if(__gcd(x,y)==1){
            cout<<1<<endl<<x<<" "<<y<<endl;
        }
        else{
            cout<<2<<endl<<1<<" "<<y-1<<endl<<x<<" "<<y<<endl;
        }
    }
    return 0;
}