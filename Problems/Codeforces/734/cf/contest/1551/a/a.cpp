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
        int x = n/3;
        int y = n/3;
        if(n-(x+(2*y))==1)
            x++;
        else if(n-(x+(2*y))==2)
            y++;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}  
