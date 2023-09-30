#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,x,y,k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        lli a = y*k;
        lli need = k+a;
        cout<<fixed<<setprecision(0);
        cout<<ceil((need*1.0/(x-1)))<<endl; 

    }
    return 0;
}

