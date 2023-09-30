#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int n,m;
pair<int,int> f(int idx){
    pair<int,int> ans = {idx/m,idx%m};
    return ans;
};
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};  
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  

bool valid(int x,int y){
    if(x>=n || y>=m)return false;
    if(x<0 || y<0)return false;
    return true;
}

bool valid_grid(vector<string> &grid){
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]<='9' && grid[i][j]>='0'){
                int cont = 0;
                for(int k = 0;k<8;k++){
                    int nx = i+fx[k];
                    int ny = j+fy[k];
                    if(!valid(nx,ny))continue;
                    if(grid[nx][ny]== '*')cont++;
                }
                int li = grid[i][j]-'0';
                if(cont!= li)return false;
            }
        }
    }
    return true;
}

int main(){__
    cin>>n>>m;
    vector<string> grid(n);
    for(auto &c:grid)cin>>c;
    int cont = 0;
    int mn = (n*m)+1;
    int mx = 1<<(n*m);
    for(int i = 0;i<1<<(n*m);i++){
        int mask = i;
        bool flag = true;
        int x,y;
        vector<string> copy = grid;
        for(int j = 0;j<n*m;j++){
            if((mask>>j)&1){
                tie(x,y) = f(j);
                if(grid[x][y]<='9' && grid[x][y]>='0'){
                    flag = false;
                    break;
                }
                else
                    copy[x][y] ='*';
            }
        }        
        if(!flag)continue;
        if(valid_grid(copy)){
            int mines = __builtin_popcount(mask);
            if(mines<mn){
                mn = mines;
                cont = 1;
            }
            else if(mines == mn)cont++;
        }
    }
    if(mn == (n*m)+1)cout<<0<<endl;
    else
        cout<<cont<<" "<<mn<<endl;
    return 0;
}  

