#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,s,v,p;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 0;
        for(int i = 0;i<n;i++){
            cin>>s>>v>>p;
            ans = max(ans,(p/(s+1))*v);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
