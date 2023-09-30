#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef double ld;
signed main(){__
	int t= 1,n;
    ld x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ld> a(n);
        vector<ld> b(n);
        int ia = 0,ib=0;
        for(int i = 0;i<2*n;i++){
            cin>>x>>y;
            if(x==0)a[ia++]=y*y;
            else b[ib++]=x*x;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ld ans =0;
        for(int i = 0;i<n;i++)
            ans+= sqrt(a[i]+b[i]);
        
        cout<<fixed<<setprecision(12);
        cout<<ans<<endl;
    }
    return 0;
}  
