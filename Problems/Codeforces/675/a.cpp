#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<max({a,b,c})<<endl;
    }
    return 0;
}

