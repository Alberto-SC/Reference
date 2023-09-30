#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b,s;
    cin>>t;
    while(t--){
        cin>>a>>b>>n>>s;
        int x = s/n;
        x = min(a,x);
        int r = s-(n*x);
        if(r<=b)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
