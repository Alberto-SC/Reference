#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        for(int i = 0;i<min(a,b);i++){
            cout<<"01";
        }
        if(b>a){
            for(int i = 0;i<b-a;i++)
                cout<<"1";
        }
        else{
            for(int i = 0;i<a-b;i++)
                cout<<"0";
        }
        cout<<endl;
    }
}   