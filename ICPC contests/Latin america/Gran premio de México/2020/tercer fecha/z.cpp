#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
cont lli mod = 1e9+7;
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        lli y = (n+1*n)/2;
        y%=mod;
        (y*=m+1)%=mod;
        cout<<y<<endl;
    }

    return 0;  
}  

