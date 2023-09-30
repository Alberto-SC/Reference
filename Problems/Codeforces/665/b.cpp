#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n,a,b,c,x,y,z;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cin>>x>>y>>z;
        lli two = min(c,y)*2;
        c-=two/2;
        y-=two/2;
        if(c+a>z){
            cout<<two<<endl;
        }
        else {
            z-=c+a;
            lli ans = two-(z*2);
            cout<<ans<<endl;
        }
    
    }
    return 0;
}

