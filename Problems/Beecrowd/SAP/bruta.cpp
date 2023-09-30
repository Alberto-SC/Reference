#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld long double

const ld ERROR = 1e-9;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)

signed main(){__
    int h,m,s;
    cin>>h>>m>>s;
    ld A = 360.0/h,B  = 360.0/m , C =360.0/s;
    cout<<fixed<<setprecision(4);
    for(int i = 0;i<h;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<s;k++){
                if(EQ(A*i , B*j)  &&EQ(B*j, C*k)){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
}   