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
        if(n%3==0 ||n%3 == 2){
            for(int i = 0;i<n/3;i++)
                cout<<21;
            if(n%3)
                cout<<2;
        }
        else{
            for(int i = 0;i<n/3;i++)
                cout<<12;
            cout<<1;
        }
        cout<<endl;
    }
}   