#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int maxn = 1000*1007;
int top;
const int inf = 1e9+7;
int q[maxn];
int dist[2][maxn];
vector<int> graph[maxn];
int fx[] = {1,-1, 0,0};
int fy[] = {0, 0,-1,1};
int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<string> grid(n);
    for(auto &c:grid)cin>>c;
    auto f = [&](int x,int y){
        return (x*m)+y;
    };
    auto valid= [&](int x,int y){
        if(x>=n || y>=m)return false;
        if(x<0 || y<0 )return false;
        return true;
    };

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny))
                    graph[f(i,j)].push_back(f(nx,ny));
            }
        }
    }
    for(int i = 0;i<n*m;i++){
        dist[0][i] = inf;
        dist[1][i] = inf;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int cont = 0;
            if(grid[i][j]== '1')continue;
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny) && grid[nx][ny]==grid[i][j])cont++;
            }
            if(cont){
                q[top++] = f(i,j);
                dist[0][f(i,j)] = 0;
            }
        }
    }
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[0][v]<= dist[0][u]+1)continue;
            dist[0][v]  = dist[0][u]+1;
            q[top++] = v;
        }
    }
    top = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]== '0')continue;
            int cont = 0;
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny)  && grid[nx][ny]== grid[i][j])cont++;
            }
            if(cont){
                q[top++] = f(i,j);
                dist[1][f(i,j)]= 0;
            }
        }
    }
    for(int i = 0;i<top;i++){
        int u= q[i];
        for(auto v:graph[u]){
            if(dist[1][v]<=dist[1][u]+1)continue;
            dist[1][v] = dist[1][u]+1;
            q[top++] = v;
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<dist[0][f(i,j)]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(t--){
        lli u,v,time;
        cin>>u>>v>>time;
        u--,v--;
        int cell = f(u,v);
        if(dist[0][cell]== dist[1][cell])cout<<grid[u][v]<<endl;
        else if(dist[0][cell]<dist[1][cell]){
            if(time<=dist[0][cell])cout<<grid[u][v]<<endl;
            else if(time&1)cout<<1<<endl;
            else cout<<0<<endl;
        }
        else{
            if(time<=dist[1][cell])cout<<grid[u][v]<<endl;
            else if(time&1)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;

}