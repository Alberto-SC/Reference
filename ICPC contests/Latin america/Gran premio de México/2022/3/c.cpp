#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int cont;
bool graph[1007][1007][4];
bool vis[1007][1007];

vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};
int N = 1001;
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>N || y>N)return false;
    return true;
}

void H(int y,int x1,int x2){
    for(int i = x1;i<=x2;i++){
        graph[i][y][3] = false;
        graph[i][y-1][2] = false;
    }
}
void V(int x,int y1 ,int y2){
    for(int i = y1;i<=y2;i++){
        graph[x][i][1] = false;
        graph[x-1][i][0] = false;
    }
}


void bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    vis[a][b] = true;
    while(!q.empty()){
        auto z = q.front();
        q.pop();
        int x = z.first;
        int y = z.second;
        cont++;
        for(int i = 0;i<4;i++){
            if(!graph[x][y][i])continue;
            int nx = fx[i]+x;
            int ny = fy[i]+y;
            if(valid(nx,ny) && !vis[nx][ny]){
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
            
        }
    }
}

signed main(){__
    int T = 1,n,x,y,nx,ny;
    memset(graph,true,sizeof(graph));
    cin>>n;
    cin>>x>>y;
    for(int i = 0;i<n;i++){
        cin>>nx>>ny;
        if(nx == x){
            if(ny>y)
                V(x,y,ny-1);
            else 
                V(x,ny,y-1);
        }
        else{
            if(nx>x)
                H(y,x,nx-1);
            else 
                H(y,nx,x-1);
        }
        x = nx;
        y = ny;
    }
    int ans = 0;
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=N;j++){
            if(!vis[i][j]){
                cont = 0;
                bfs(i,j);
                if(i && j)ans = max(ans,cont);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}