#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,a,b,c,d;
    while(t--){
        cin>>a>>b>>c>>d;
        cout<<max({a*c,a*d,b*c,b*d});
    }
    return 0;
}

