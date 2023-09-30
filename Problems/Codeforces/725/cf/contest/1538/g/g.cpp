#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,y,a,b;
    while(t--){
        cin>>x>>y>>a>>b;
        int ans = 0;
        int diff = abs(a-b);    
        while(1){
            int d2 = abs(x-y);
            int s = ceil((d2*1.0)/diff);
            // cout<<x<<" "<<y<<" "<<d2<<" "<<s<<" ";
            if(x>y){
                s = min(s,x/max(a,b));
                s = min(s,y/min(a,b));
                x-=s*max(a,b);
                y-=s*min(a,b);
            }
            else{
                s = min(s,x/min(a,b));
                s = min(s,y/max(a,b));
                x-=s*min(a,b);
                y-=s*max(a,b);
            }
            // cout<<s<<endl;
            ans+=s;
            if(!s)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
