#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct p{
    int l,r,v;
};

signed main(){__
	int t= 1,n,k,l,r,x;
    while(t--){
        cin>>n>>k;
        vector<p> z(n); 
        for(int i = 0;i<n;i++){
            cin>>l>>r>>x;
            z[i]  = {l-1,r-1,x};
        }
        int mx = 0;

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int cost = (j-i)*k;
                int s = 0;
                for(int k = i;k<=j;k++){
                    if(z[k].l>=i && z[k].r<=j)
                        s+=z[k].v;
                }        
                mx = max(mx,s-cost);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}  
