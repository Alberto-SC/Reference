
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
char grid[2007][2007];
bool vis[2007][2007];
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1}; 
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1}; 
#define fi first
#define se second
int n,m;
bool valid(int a,int b){
    // cout<<a<<" "<<b<<" "<<n<<" "<<m<<endl;
    if(a<0 || b<0)return false;
    if(a>=n || b>=m)return false;
    return true;
}

void bfs(int a,int b){
    // cout<<a<<" "<<b<<endl;
    vis[a][b] = true;
    for(int i = 0;i<8;i++){
        int nx = a+fx[i];
        int ny = b+fy[i];
        // cout<<nx<<" "<<ny<<endl;
        if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny] == '#')
            bfs(nx,ny);
    }
}

pair<int,int> eid = {0,0};
void get_limits(int x,int y){
    vis[x][y] = true;
    eid = max(eid,{x,y});
    for(int i = 0;i<8;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]== '#')
            get_limits(nx,ny);
    }
}

int main(){
    cin>>n>>m;
    swap(n,m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            vis[i][j] = false;
        }
    }
    vector<pair<int,int>> comp;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '#'){
                bfs(i,j);
                if(i != 0 && j != 0)
                    comp.push_back({i,j});
            }
            
        }
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            vis[i][j] = false;
    
    int contA = 0,contB = 0,contC = 0;
    for(int i = 0;i<comp.size();i++){
        pair<int,int> esi = {comp[i].fi,comp[i].se};
        eid = {0,0};
        get_limits(comp[i].fi,comp[i].se);
        // cout<<esi.fi<<" "<<esi.se<<" "<<eid.fi<<" "<<eid.se<<endl;
        bool flag = false;
        int a,b;
        for(a = esi.fi;a<=eid.fi;a++){
            for(b = esi.se;b<=eid.se;b++)
                if(grid[a][b] == '.'){flag = true;break;}
            if(flag)break;
        }
        // cout<<a<<" "<<b<<endl;
        if(!flag)continue;
        int vx =b-esi.se;
        int c;
        int negro = -1;
        for(c = b;c<=eid.se;c++)
            if(grid[esi.fi+a][c]== '#'){negro = c;break;}
        // cout<<negro<<" "<<vx<<endl;
        int vy;
        int ancho = (eid.se-esi.se)+1;
        int largo = (eid.fi-esi.fi)+1;
        if(negro == -1){
            vy = ancho-(2*vx);
            if(largo == (2*vy)+(3*vx) && ancho == (2*vx)+vy)
                contC++;
            continue;
        }
        else{
            vy = negro-b;
        }
        // cout<<ancho<<" "<<largo<<" "<<vy<<endl;
        if(grid[eid.fi][b]== '#'){
            if(largo == (2*vy)+(3*vx) && ancho == (2*vx)+vy){
            
               contB++;
            }
        }
        else{
            if(largo == (2*vy)+(3*vx) && ancho == (2*vx)+vy)
                contA++;
        }
    }
    cout<<contA<<" "<<contB<<" "<<contC<<endl;
    return 0;
}  

