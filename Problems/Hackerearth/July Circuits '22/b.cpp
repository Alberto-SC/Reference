#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if(a>=n){
            cout<<1<<endl;
            continue;
        }
        if(b>a){
            cout<<-1<<endl;
            continue;
        }
        int x = a-b;
        int l = 1,r = 1e10;
        while(l+1<r){
            int m = (l+r)>>1;
            if(m*x>=n)
                r = m;
            else 
                l = m;
        }
        if(r ==1e10)cout<<-1<<endl;
        else{
            int current = x*r;
            current+=b;
            int diff = current-n;
            int ans = (r*2)-1;
            ans-=(diff/x)*2;
            cout<<ans<<endl;
        }
    }

    return 0;
}  
