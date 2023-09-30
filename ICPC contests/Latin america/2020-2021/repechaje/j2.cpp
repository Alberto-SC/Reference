#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
signed main(){__
    int T = 1,n,C,F,B,S;
    cin>>T;
    while(T--){
        cin>>C>>F>>B>>S;
        int lcm = 12;
        ld x = 360.0/F;
        ld y = 360.0/B;
        for(int i = 1;i<=12;i++){
            if(fmod(i*30.0,x)==0.0 && fmod(i*30.0,y)==0.0 ){
                lcm =i;
                break;
            }
        }
        ld ans = (S*12.0)/(C*lcm*1.0);
        cout<<ceil(ans)*lcm<<endl;
    }
    return 0;
}