#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int B = 9;
signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        int cont;
        cin>>cont;
        int mn = 0;
        int ans = 0;
        int bit = 0;
        while(bit<30 && cont > mn){
            cout<<"- "<<(1<<bit)<<endl;
            int x;
            cin>>x;

            if(x == cont-1){
                ans|=(1<<bit);
                bit++;
                cont = x;
            }
            else{
                int diff = x-cont;
                diff++;
                ans |=(1<<(bit+diff));
                bit+=diff+1;
                mn+=diff;
                cont = x;
            }
        }
        cout<<"! "<<ans<<endl;
    }
    // cout<<ans<<" "<<firstN<<endl;
    return 0;
}