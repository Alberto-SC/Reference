#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double 

int A,B;
ld f(int x){
    ld ans = (A/(sqrt(x+1)))+(x*B);
    return ans;
}

signed main(){__
    cin>>A>>B;
    int l = 0,r = A/B;
    while (r - l > 2) {
        int m1 = (l * 2 + r) / 3;
        int m2 = (l + r * 2) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    ld ans = 1e18+7;
    for(int i = l; i <= r; i++)
        ans = min(ans , f(i));
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}