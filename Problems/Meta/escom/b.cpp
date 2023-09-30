#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int mx;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};  
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  

int M[200][200];
bool visit[200][200];

int n,m;
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>=m)return false;
    return true;
}
void bfs(int x,int y){
    mx++;
    visit[x][y] = true;
    for(int i = 0;i<8;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && M[nx][ny]== 1 &&!visit[nx][ny]){
            bfs(nx,ny);
        }
    }
}

signed main(){__
	int t= 1;
    cin>>t;
    int test = 1;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>M[i][j];
                visit[i][j] = false;
            }
        } 
        int ans =0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(M[i][j] ==1 && !visit[i][j]){
                    mx = 0;
                    bfs(i,j);
                    ans = max(ans,mx);
                }
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;
        test++;
    }
    return 0;
}  
