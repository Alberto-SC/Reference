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
        int x = 1;
        while(x*x<n){
            x++;
        }
        int f = (x-1)*(x-1)+1;
        if(n<=(f+x)-1){
            cout<<n-(f-1)<<" "<<x<<endl;
        }
        else{
            f = f+(x-1);
            cout<<x<<" "<<x-(n-f)<<endl;
        }
    }
    return 0;
}  
