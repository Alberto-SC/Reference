#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,r,b,k;
    cin>>t;
    while(t--){
        cin>>r>>b>>k;
        if(r>b)swap(r,b);
        int gcd = __gcd(r,b);
        r/=gcd;
        b/=gcd;
        if((k-1)*r+1>=b )cout<<"OBEY"<<endl;
        else cout<<"REBEL"<<endl;
    }
    return 0;
}  
  