#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,x1,x2,y1,y2;
    cin>>t;
    while(t--){
        cin>>n>>m>>x1>>y1>>x2>>y2;
        int dr = 1,dc = 1;
        int ans = 0;
        while(1){
            if(x1 == x2 || y1 == y2)break;
            if(x1 == n)dr *=-1;
            if(y1 == m)dc *=-1;
            x1+=dr;
            y1+=dc;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
