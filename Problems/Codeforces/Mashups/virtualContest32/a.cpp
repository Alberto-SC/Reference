#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        vector<string>grid(n);
        for(int i = 0;i<n;i++)
            cin>>grid[i];
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]== '*')continue;
                if(j+1<m && grid[i][j]== '.' && grid[i][j+1] == '.' && y<=2*x){
                    ans+=y;
                    grid[i][j+1] = '*';
                }
                else 
                    ans+=x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
