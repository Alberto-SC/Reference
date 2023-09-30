#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int diff = abs(b-a);
        cout<<fixed<<setprecision(0);
        cout<<ceil(diff/10.0)<<endl;
    }
    return 0;
}

