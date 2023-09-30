#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int cols = m;
        int rows = n;
        int grid[n][m];
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){  
                if(grid[i][j] == 1){rows--;break;}
            }
        }
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){  
                if(grid[j][i] == 1){cols--;break;}
            }
        }
        int x = min(rows,cols);
        if(x&1)cout<<"Ashish"<<endl;
        else cout<<"Vivek"<<endl;

    }
    return 0;
}