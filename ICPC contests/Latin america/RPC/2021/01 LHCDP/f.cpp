#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1000007;
vector<vector<char>> grid(1007,vector<char>(1007));
const int inf = 1e9+7;
int n,m;
int f(int x,int y){
    return (x*m)+y;
}
pair<int,int> coords(int x){
    return {x/m,x%m};
}

bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(y>=m||x>=n)return false;
    return true;
}
vector<int> fx = {+1,+0,+0,-1};
vector<int> fy = {+0,-1,+1,+0};
vector<int> parent(maxn);
vector<int> q(maxn*20);
vector<int> dist(maxn);
void bfs(int x,int y){
    for(int i = 0;i<n*m;i++){
        dist[i] = inf;
    }
    dist[f(x,y)] = 0;
    int idx = 0;
    q[idx++] =f(x,y); 
    for(int i = 0;i<idx;i++){
        int u = q[i];
        for(int j = 0;j<4;j++){
            int nx = coords(u).first+fx[j];
            int ny = coords(u).second+fy[j];
            if(valid(nx,ny) && grid[nx][ny]== '.'){
                if(dist[u]+1<dist[f(nx,ny)]){
                    dist[f(nx,ny)] = dist[u]+1;
                    parent[f(nx,ny)] = u;
                    q[idx++] = f(nx,ny);
                }
            }
        }
    }
}
int main(){__
	int t= 1;
    int id = 1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int x,y;
        swap(n,m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
                if(grid[i][j]== '@'){
                    x = i;
                    y = j;
                }
            }
        }
        bfs(x,y);
        int mx = 0;
        for(int i = 0;i<n*m;i++){
            // cout<<dist[i]<<" ";
            if(dist[i]!= inf){
                mx = max(mx,dist[i]);
            }
        }
        int cont = 0;
        vector<string> paths;
        for(int i = 0;i<n*m;i++){
            if(dist[i]==mx){
                cont++;
                string path = "";
                int v = i;
                while(v != f(x,y)){
                    auto pr = coords(parent[v]);
                    auto me = coords(v);
                    if(pr.first==me.first){
                        if(pr.second<me.second)
                            path+="R";
                        else 
                            path+="L";
                    } 
                    else{
                        if(pr.first<me.first)
                            path+="D";
                        else 
                            path+="U";
                    }
                    v = parent[v];
                }
                reverse(path.begin(),path.end());
                paths.push_back(path);
            }
        }
        cout<<"Case "<<id<<":"<<endl;
        cout<<cont<<" "<<mx<<endl;

        sort(paths.begin(),paths.end());
        for(int i = 0;i<paths.size();i++){
            cout<<paths[i];
            if(i!=paths.size()-1)cout<<endl;
        }
        if(id)cout<<endl;
        id++;
    }
    return 0;
}  

