#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,p,a,b,c;
    cin>>t;
    while(t--){
        cin>>p>>a>>b>>c;
        int x = p/a;
        int y = p/b;
        int z = p/c;
        if(p%a)x++;
        if(p%b)y++;
        if(p%c)z++;
        cout<<min({(a*x)-p,(b*y)-p,(c*z)-p})<<endl;
    }
    return 0;
}  
