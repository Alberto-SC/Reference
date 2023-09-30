#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b>1){
            if(b==2)b*=2;
            cout<<"YES"<<endl;
            int z = a*b;
            int x = a*(b-1);
            int y = a;
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}  
