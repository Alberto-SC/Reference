#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        int sum = 0;
        int mn = 10000;
        int ng = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>grid[i][j],sum+=abs(grid[i][j]),grid[i][j]<=0?ng++:ng+=0,mn =min(abs(grid[i][j]),mn);
        // cout<<ng<<endl;
        if(ng%2 ==0)
            cout<<sum<<endl;
        else 
            cout<<sum-(2*mn)<<endl;
    }
    return 0;
}  

