#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,a,b,n;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        if(a+n<=b){
            cout<<0<<endl;
        }
        else{
            int l = -1,r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                if(a+m>b+n-m)
                    r = m;
                else 
                    l = m;
            }
            // cout<<r<<endl;
            cout<<(n-r)+1<<endl;
        }
    }
    return 0;
}  
