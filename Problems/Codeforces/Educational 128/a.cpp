#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(c<=b){
            if(c<a &&d<a)cout<<a+c<<endl;
            else if(c<a && d>=a)cout<<a<<endl;
            else cout<<c<<endl;
        }
        else cout<<a+c<<endl;

    }
}
