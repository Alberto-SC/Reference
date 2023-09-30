#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int z = min(x,y);
        x-=z;
        y-=z;
        int ans = z*2;
        if(x){
            ans+= x*2;
            ans--;
        }
        if(y){
            ans+=y*2;
            ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

