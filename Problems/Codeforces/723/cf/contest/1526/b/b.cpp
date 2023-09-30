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
        int mod = n%11;
        if(111*mod<=n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
