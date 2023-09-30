#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld double

const ld ERROR = 1e-12;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)

signed main(){__
    int h,m,s;
    cin>>h>>m>>s;
    ld A = 360.0/h,B  = 360.0/m , C =360.0/s;
    int ans = 0;
    for(int i = 0;i<h;i++){
        if(EQ(remainder(i*A,B),0.0)  && EQ(remainder(i*A,C),0.0)){
            ans++;
            // cout<<i<<" "<<(i*A)/B<<" "<<(i*A)/C<<endl;
        }
    }
    cout<<ans<<endl;
    for(int i = 0;i<h;i++){
        if(EQ(remainder(i*A,B),0.0)  && EQ(remainder(i*A,C),0.0)){
            cout<<i<<" "<<(i*A)/B<<" "<<(i*A)/C<<endl;
        }
    }
}   