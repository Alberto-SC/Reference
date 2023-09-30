#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k<=n){
            if(n&1){
                if(k&1)cout<<0<<endl;
                else cout<<1<<endl;
            }
            else {
                if(k&1)cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
        else cout<<k-n<<endl;

    }
    return 0;
}

