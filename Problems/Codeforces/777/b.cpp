#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool vis[107][107];
char M[107][107];
int cont,mnx,mxx,mny,mxy;
        
vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};

int n,m;
bool valid(int x,int y){
    if(x<0 || y<0 )return false;
    if(x>=n || y>= m)return false;
    return true;
}

void bfs(int x,int y){
    vis[x][y] = true;
    mnx = min(mnx,x);
    mxx = max(mxx,x);
    mny = min(mny,y);
    mxy = max(mxy,y);
    cont++;
    for(int k = 0;k<4;k++){
        int nx = x+fx[k];
        int ny = y+fy[k];
        if(valid(nx,ny)  && !vis[nx][ny] && M[nx][ny] =='1')
            bfs(nx,ny);

    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>M[i][j],vis[i][j] = false;

        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(!vis[i][j] && M[i][j] == '1'){
                    cont = 0;
                    mnx = 1e15;
                    mxx = -1;
                    mny = 1e15;
                    mxy = -1;
                    bfs(i,j);
                    int w = (mxy-mny)+1;
                    int h = (mxx-mnx)+1;
                    int total = w*h;
                    if(cont!=total)flag = false;
                }
            
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}   