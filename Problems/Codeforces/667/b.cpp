#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,a,b,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y>>n; 
        lli ans1,aux = n,auxa = a,auxb = b;
        lli z = min(a-x,n);
        // cout<<z<<" "<<a-x<<" "<<n<<endl;
        a-=z;
        n-=z;
        z = min(b-y,n);
        // cout<<a<<" "<<n<<endl;
        b-=z;
        n-=z;
        ans1 = a*b;
        lli ans2;
        a = auxa;
        b = auxb;
        n = aux;
        z = min(b-y,n);
        b-=z;
        n-=z;
        z = min(a-x,n);
        a-=z;
        ans2 = a*b;
        cout<<min(ans1,ans2)<<endl;

    }
    return 0;
}

