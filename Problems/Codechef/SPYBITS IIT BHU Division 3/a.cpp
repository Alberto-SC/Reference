#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,h,x,y,c;
    cin>>t;
    while(t--){
        cin>>h>>x>>y>>c;
        int z = x+(y/2);
        if(z*h<=c)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
