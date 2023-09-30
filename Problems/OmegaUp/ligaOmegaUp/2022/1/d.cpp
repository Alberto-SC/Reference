#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int M[2000][2000];
bool vis[2000][2000];
int n,m;

bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>= m )return false;
    return true;
}

const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  
int mx = 0;
void dfs(int x,int y){
    mx++;
    vis[x][y] = true;
    for(int i = 0;i<8;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && M[nx][ny]== 1 && !vis[nx][ny])
            dfs(nx,ny);
    }
}


signed main(){__
	int t= 1;
    cin>>t;
    int id = 1;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>M[i][j];
                vis[i][j] = false; 
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j]&& M[i][j] ==1){
                    mx = 0;
                    dfs(i,j);
                    ans = max(ans,mx);
                }
            }
        }
        cout<<"Case #"<<id<<": "<<ans<<endl;
        id++;
    }
    return 0;
}  
