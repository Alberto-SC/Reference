#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        long double H,L;
        cin>>H>>L;
        long double T = ((H*H)+(L*L))/(2*H);
        cout<<fixed<<setprecision(8);
        cout<<T-H<<endl;
    }
    return 0;
}