#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> fx = {+0,+1,+0,-1};
vector<int> fy = {-1,+0,+1,+0};

int n,m;
char grid[1001][1001];
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>=m)return false;
    return true;
}
const int maxn = 1001*1001;
vector<int> graph[maxn];
const int INF = 1000000000;
void add_edge(int u,int v){
    graph[u].push_back(v);
}

int q[maxn*10];
vector<int> dist(maxn);
int topQ;
void bfs(int s,int n){
    for (int i = 0; i<n;i++)
        dist[i] = INF;
    dist[s] = 0;
    q[topQ++] = s;
    for (int i = 0; i < topQ; i++) {
        int u = q[i];
        for (int v : graph[u]) {
            if (dist[v] <= dist[u] + 1 || grid[v/m][v%m]!='.') continue;
            dist[v] = dist[u] + 1;
            q[topQ++] = v;
        }
    }
}



signed main(){
	int q,a,b,x,y;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]== 'E'){ 
                x = i;
                y = j;
            }
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny)){
                    add_edge((i*m)+j,(nx*m)+ny);
                }
            }
        }
    }
    bfs((x*m)+y,n*m);
    vector<char> mp = {'L','D','R','U'};
    cin>>q;
    while(q--){
        cin>>a>>b;
        a--,b--;
        if(grid[a][b]== 'E')
            cout<<"E"<<endl;
        else if(grid[a][b]=='#')
            cout<<"W"<<endl;
        else if(grid[a][b]=='X')
            cout<<"X"<<endl;
        else {
            if(dist[(a*m)+b]==INF)
                cout<<"?"<<endl;
            else{
                int mn =INF,idx = -1;
                for(int i = 0;i<4;i++){
                    int nx = a+fx[i];
                    int ny = b+fy[i];
                    if(valid(nx,ny) && dist[(nx*m)+ny]<mn){
                            mn = dist[(nx*m)+ny];
                            idx = i;
                    }
                }
                cout<<mp[idx]<<endl;
            }
        }
    }  

    return 0;
}  
