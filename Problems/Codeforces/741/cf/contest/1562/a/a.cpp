#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,l,r,b,a;
    cin>>t;
    while(t--){
        cin>>l>>r;
        a = r;
        b = max((r/2)+1,l);
        b = min(b,r);
        cout<<a%b<<endl;
    }
    return 0;
}  
