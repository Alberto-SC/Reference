#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 1007;
const int inf = 1000000007;
int n,m;
char grid[maxn][maxn];
vector<int> fx = {1,0, 0,-1};
vector<int> fy = {0,1,-1, 0};
int dist[maxn*maxn];

vector<int> graph[maxn*maxn];
bool valid(int x,int y){
    if(x>=n || x<0 )return false;
    if(y>=m || y<0)return false;
    if(grid[x][y] == 'T')return false;
    return true;
}
int q[maxn*maxn*10];
int top;
void bfs(int n,int s){
    for(int i  = 0;i<n;i++)dist[i] = inf;
    dist[s] = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[v]<= dist[u]+1)continue;
            dist[v] = dist[u]+1;
            q[top++] = v;
        }
    }
}

int main(){__
    cin>>n>>m;
    int x,y,a,b;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 'E')x = i,y = j;
            if(grid[i][j] == 'S')a = i,b = j;
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny) && grid[i][j]!= 'T')graph[(i*m)+j].push_back((nx*m)+ny);
            }
        }
    }
    bfs(n*m,(x*m)+y);
    // for(int i = 0;i<n;i++)
    //     for(int j = 0;j<m;j++)  
    //         cout<<dist[(i*m)+j]<<" \n"[j == m-1];
    int ans = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(grid[i][j]>='1' && grid[i][j]<='9' && dist[(i*m)+j]<= dist[(a*m)+b])
                ans+= grid[i][j]-'0';
         
    cout<<ans<<endl;
    return 0;
}