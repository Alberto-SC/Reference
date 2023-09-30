#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<bool>> res(1007,vector<bool> (1007));
vector<vector<char>> grid(1007,vector<char> (1007));

int t= 1,n,m;
void try_put(int x,int y){
    if(x+2>=n || y+2>=m)    
        return ;
    bool flag = true;
    for(int i = x;i<x+3;i++){
        for(int j = y;j<y+3;j++){
            if(i== x+1 && j == y+1)continue;
            if(grid[i][j]== '.')flag = false;
        }
    }
    if(!flag)return;
    for(int i = x;i<x+3;i++){
        for(int j = y;j<y+3;j++){
            if(i== x+1 && j == y+1)continue;
            res[i][j]= true;
        }
    }

}
signed main(){__
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]== '#'){
                    try_put(i,j);
                }
            }
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]== '#' && !res[i][j]){
                    flag = false;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
