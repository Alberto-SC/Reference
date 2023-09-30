#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n%2==0){
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++){
                if(i&1)cout<<-1<<" ";
                else cout<<1<<" ";
            }
        }
        else{
            if(n==3){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
                int x = n/2;
                for(int i = 0;i<n;i++){
                    if(i&1)cout<<x<<" ";
                    else cout<<-(x-1)<<" ";
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}