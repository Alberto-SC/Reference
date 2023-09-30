#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1000000007;
int main(){__
	lli t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        n++;
        m++; 
        lli y = ((n+1)*n)/2;
        y%=mod;
        (y*=m)%=mod;
        cout<<y<<endl;
    }

    return 0;  
}  

