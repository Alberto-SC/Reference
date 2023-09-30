#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        int x = s/n;
        int l = n/2;
        if(n%2==0)
            l--;
        int ans = s/(n-l);
        cout<<ans<<endl;
    }
    return 0;
}  
