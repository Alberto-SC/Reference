#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<char>> grid(n,vector<char> (n));
        pair<int,int> pos1 = {-1,-1};
        pair<int,int> pos2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]== '*' && pos1.first== -1)pos1 = {i,j};
                if(grid[i][j]== '*' && pos1.first!= -1)pos2 = {i,j};
            }
        }
        if(pos1.first == pos2.first){
            if(pos1.first==n-1){
                grid[pos1.first-1][pos1.second] = '*';
                grid[pos2.first-1][pos2.second] = '*';
            }
            else{
                grid[pos1.first+1][pos1.second]= '*';
                grid[pos2.first+1][pos2.second]= '*';
            }
        }
        else if(pos1.second ==pos2.second){
            if(pos1.second==n-1){
                grid[pos1.first][pos1.second-1] = '*';
                grid[pos2.first][pos2.second-1] = '*';
            }
            else{
                grid[pos1.first][pos1.second+1]= '*';
                grid[pos2.first][pos2.second+1]= '*';
            }

        }
        else {
            grid[pos1.first][pos2.second] = '*';
            grid[pos2.first][pos1.second] = '*';
        }
        for(auto c:grid){for(auto d:c)cout<<d;cout<<endl;}
    }
    return 0;
}  
