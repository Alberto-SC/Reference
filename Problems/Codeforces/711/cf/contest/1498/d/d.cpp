#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,x,y;
    cin>>n>>m;
    vector<int> ans(m+1,-1);
    vector<bool> vis(m+1);
    vis[0] = 1;

    for(int i = 1;i<=n;i++){
        cin>>t>>x>>y;
        int aux = y;
        vector<bool> nvis = vis;
        for(int j = 0;j<=m;j++){
            if(vis[j]){
                y = aux;
                int z = j;
                if(t==1){
                    z = ceil((z*1.0)+(x/100000.0));
                    while(z<=m && y--){
                        if(vis[z])break;
                        nvis[z] = true;
                        ans[z] = i;
                        z = ceil((z*1.0)+(x/100000.0)); 
                    }
                }
                else{
                    int cont = 1;
                    z = ceil(z*x/100000.0);
                    while(z<=m && y--){
                        if(vis[z])break;
                        ans[z] = i;
                        nvis[z] = true;
                        cont++;
                        z = ceil(z*x/100000.0);
                    }
                }
            }
        }
        vis = nvis;
    }

    for(int i = 1;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}  
