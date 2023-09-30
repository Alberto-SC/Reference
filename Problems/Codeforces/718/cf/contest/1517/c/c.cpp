#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int fx[]={0,+1};
const int fy[]={-1,0};

int vis[507][507];
int n;
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>=n)return false;
    return true;
}
int cont = 0;
void dfs(int x,int y,int val){
    if(vis[x][y])return;
    cont++;
    vis[x][y] = val;
    if(cont ==val)return;
    for(int i = 0;i<2;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && !vis[nx][ny] && cont<val)
            dfs(nx,ny,val);
    }
}
signed main(){__
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        cont = 0;
        dfs(i,i,nums[i]);
    }       

    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
         
    return 0;
}  
