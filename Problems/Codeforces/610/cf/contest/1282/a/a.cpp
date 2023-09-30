#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b,c,r;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>r;
        if(a>b)swap(a,b);
        int x = b-a;
        int l = c-r,r2 = c+r;
        l = max(l,a);
        r2 = min(r2,b);
        if(r2>=l)
            x-=(r2-l);
        cout<<x<<endl;
    }
    return 0;
}  
