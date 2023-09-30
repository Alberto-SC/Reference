#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,x,y,z;
    cin>>t;
    while(t--){
        cin>>a>>y>>x;
        int z = a-(y-1);
        z = max(0ll,z);
        if(z== 0)cout<<(a*x)+1<<endl;
        else 
            cout<<y*x<<endl;
        
    }
    return 0;
}  
