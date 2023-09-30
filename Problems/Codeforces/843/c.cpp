#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    cin>>T;
    while(T--){
        cin>>n>>x;
        bool flag = true;
        int l = 0,r = 1ll<<62;
        for(int i = 0;i<=61;i++){
            int a = (n>>i)&1;
            int b = (x>>i)&1;
            if(b && !a){
                flag = false;
                break;
            }
            int p2 = 1ll<<i;
            if(!b && a){
                int nxt = p2-(n%p2);
                l = max(l,nxt);
            }
            else if(b && a){
                int nxt = p2-(n%p2);
                r = min(r,nxt-1);
            }
        }
        if(l>r)flag = false;
        if(!flag)
            cout<<-1<<endl;
        else 
            cout<<n+l<<endl;

    }
    return 0;
}