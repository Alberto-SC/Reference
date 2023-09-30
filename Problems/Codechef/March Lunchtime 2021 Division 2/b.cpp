#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,r,m;
    cin>>t;
    while(t--){
        cin>>x>>r>>m;
        r*=60;
        m*=60;
        if(m<r)cout<<"NO"<<endl;
        else{
            r-=x;
            m-=x;
            if(m>=2*r)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  
