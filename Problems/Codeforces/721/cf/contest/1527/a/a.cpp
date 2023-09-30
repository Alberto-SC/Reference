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
        int x = 2;
        while(x-1<n){
            x*=2;
        }
        x/=2;
        cout<<x-1<<endl;
    }
    return 0;
}  
