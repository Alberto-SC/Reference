#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,b;
    while(t--){
        cin>>n>>b;
        cout<<ceil((b*1.0)/(n-1))<<endl;
    }
    return 0;
}  
