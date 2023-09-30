#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int a,n;
    while(cin>>a>>n){
        int pow2 = 0,pow5 = 0;
        while(a%2==0){
            pow2++;
            a/=2;
        }
        while(a%5==0){
            pow5++;
            a/=5;
        }
        if(a>1){
            cout<<"Precision Error"<<endl;
            continue;
        }

        int m = max(pow2*n,pow5*n);
        int p2 = m-(pow2*n);
        int p5 = m-(pow5*n);
        int x = 1;
        while(p2--){
            x*=2;
        }
        while(p5--){
            x*=5;
        }
        cout<<m<<" "<<x<<endl;
    }
    return 0;
}