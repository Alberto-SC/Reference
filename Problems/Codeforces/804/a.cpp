#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1)cout<<-1<<endl;
        else{
            cout<<0<<" "<<n/2<<" "<<n/2<<endl;
        }
    }
}
