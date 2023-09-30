#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,k;
    cin>>n>>t;
    while(t--){
        cin>>k;
        int l = 0,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<1<<" "<<m<<endl;
            cin>>x;
            if(m-x>=k)
                r = m;
            else
                l = m;
        }
        cout<<"! "<<r<<endl;
    }
    return 0;
}  
