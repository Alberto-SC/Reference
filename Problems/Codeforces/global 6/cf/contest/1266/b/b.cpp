#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n%14>=1 && n%14<=6 && n>=14)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
