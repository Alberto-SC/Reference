#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,l,r,x,a,b;
    cin>>T;
    while(T--){
        cin>>l>>r>>x;
        cin>>a>>b;
        if(a==b)cout<<0<<endl;
        else if(abs(a-b)>=x)cout<<1<<endl;
        else {
            if((b-l)>=x && (a-l)>=x)cout<<2<<endl;
            else if((r-b)>=x && (r-a)>=x)cout<<2<<endl;
            else if((a-l)>=x && (r-b)>=x)cout<<3<<endl;
            else if((r-a)>=x && (b-l)>=x)cout<<3<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}