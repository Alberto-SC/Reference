#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f(int x){
    if(x ==1)return 0;
    if(x&1)return f(x/2);
    else return f(x/2)+1;
}

int g(int x){
    if(x == 1)return 1;
    if(x&1)return 2*g(x/2);
    else return (2*g(x/2))+1;
}

signed main(){__
    int T = 1,n,l,r;
    cin>>T;
    while(T--){
        cin>>l>>r;
        int ans2 = 0;
        for( int y = r;y>=l;y--){
            // cout<<f(y)+g(y)<<" "<<y<<endl;
            ans2 = max(ans2,f(y)+g(y));
        }
        cout<<ans2<<endl;
    }
    return 0;
}