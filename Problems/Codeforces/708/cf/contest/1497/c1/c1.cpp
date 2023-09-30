#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n&1)cout<<n/2<<" "<<n/2<<" "<<1<<endl;
        else{
            if((n/2)&1)
                cout<<(n/2)-1<<" "<<(n/2)-1<<" "<<2<<endl;
            else
                cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        }
    }
    return 0;
}  
