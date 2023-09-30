#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k1,k2,a,b,b1,b2;
    cin>>t;
    while(t--){
        cin>>n>>k1>>k2;
        cin>>a>>b;
        b1 = n-k1;
        b2 = n-k2;
        bool flag = true;

        if(k1+k2<(2*a))flag = false;
        if(b1+b2<(2*b))flag = false;
        
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
