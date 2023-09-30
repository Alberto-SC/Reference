#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int T = 1,n;
    cin>>n;
    int mx = 0;

    cout<<1<<" "<<0<<endl;
    cin>>mx;
    for(int bit= 30;bit>=0;bit--){

        for(int j = 1;j<=n;j++){
            cout<<j<<" "<<((1<<bit)|ac[j])<<endl;
            int nmx;
            cin>>nmx;
            if(nmx == 0){
                cout<<0<<endl;
                return;
            }
            if(nmx>mx){
                cout<<j<<" "<<nmx<<endl;
                if(nmx  == 0){
                    cout<<0<<endl;
                    return ;
                }
            }
            else if(nmx < mx){
                
            }

            mx = max(mx,nmx);
        }

        if(mx && (1<<bit)!= 0){
            for(auto c:tbd){
                ac[c]|= (1<<bit);
            }
        }
    }
    cout<<0<<endl;
    return 0;
}