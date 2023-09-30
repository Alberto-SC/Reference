#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<1<<endl;
        else if(n&1){
            int x = n-1;
            int y = (n/2);
            x+=2*((y*y)-1)+1;
            cout<<x<<endl;
        }
        else{
            int x = n-1;
            int y = (n/2)-1;
            x+=2*((y*y)+y);
            cout<<x<<endl;
        }
    }
}   