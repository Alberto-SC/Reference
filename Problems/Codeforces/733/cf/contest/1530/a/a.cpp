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
        int mx =0;
        while(n){
            mx = max(mx,n%10);
            n/=10;
        }
        cout<<mx<<endl;
    }
    return 0;
}  
