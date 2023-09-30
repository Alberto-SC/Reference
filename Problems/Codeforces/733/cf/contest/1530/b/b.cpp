#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> grid(n,string(m,'0'));
        if(n<m){
            for(int i = 0;i<m;i+=2){
                grid[0][i] = '1';
                grid[n-1][i] = '1';
            }
            for(int i = 2;i<n-2;i+=2){
                grid[i][0] = '1';
                grid[i][m-1] = '1';
            }
        }
        else{
            for(int i = 0;i<n;i+=2){
                grid[i][0] = '1';
                grid[i][m-1] = '1';
            }
            for(int i = 2;i<m-2;i+=2){
                grid[0][i] = '1';
                grid[n-1][i] = '1';
            }
        }
        for(auto c:grid)cout<<c<<endl;
        cout<<endl;
    }
    return 0;
}  
