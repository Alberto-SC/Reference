#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>d;
        if(a>b)swap(a,b);
        if(a==0 || b == 0 || ((d+1)*a)<b)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}  
