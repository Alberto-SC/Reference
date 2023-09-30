#include <bits/stdc++.h>
using namespace std;
set<pair<int,int>> ans;
int n;
vector<vector<int>> grid(101,vector<int>(101,-1));
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
void getans(int x,int y){
    int nx =x,ny = y;
    for(int i = 0;i<8;i++){
        int cont = 0;
        while(nx>=0 && nx<n && ny>=0 && ny<n){
            if(grid[nx][ny] == 0)cont++;
            else break;
            nx = nx+fx[i];
            ny = ny+fy[i];
        }
        if(cont >=4){
            for(int j = 0;j<8;j++){ 
                if(j == i)continue;
                int cont2 = 0;
                int nnx =x,nny = y;
                while(nnx>=0 && nnx<n && nny>=0 && nny<n){
                    if(grid[nx][ny] == 0)cont2++;
                    else break;
                    nx = nx+fx[j];
                    ny = ny+fy[j];
                }
                if(cont2 >=4){
                    if(x+fx[i]<n && x+fx[i]>=0 && y+fx[i]>=0 && y+fx[i]<n)ans.insert({x+fx[i],y+fy[i]});
                    if(x+fx[j]<n && x+fx[j]>=0 && y+fx[j]>=0 && y+fx[j]<n)ans.insert({x+fx[j],y+fy[j]});
                    if(x+fx[j]<n && x+fx[j]>=0 && y+fx[j]>=0 && y+fx[j]<n)ans.insert({x+fx[j],y+fy[j]});
                    if(x+(4*fx[j])<n && x+(4*fx[j])>=0 && y+(4*fx[j])>=0 && y+(4*fx[j])<n)ans.insert({x+(4*fx[j]),y+(4*fy[j])});
                    if(x+(4*fx[i])<n && x+(4*fx[i])>=0 && y+(4*fx[i])>=0 && y+(4*fx[i])<n)ans.insert({x+(4*fx[i]),y+(4*fy[i])});
                }
            }
        }
    }
}

void getans2(int x,int y){
    int nx = x;
    int ny = y;
    // if(x == 2 && y == 4)cout<<"HOLA"<<endl;
    for(int i = 0;i<8;i++){
        int cont = 0,cont2 = 0;
        nx = nx+fx[i];
        ny = ny+fy[i];
        while(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
            cont++;
            nx = nx+fx[i];
            ny = ny+fy[i];
        }
        nx = x;
        ny = y;
        nx = nx-fx[i];
        ny = ny-fy[i];
        while(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
            cont2++;
            nx = nx-fx[i];
            ny = ny-fy[i];
        }
        if(cont+cont2>=4)ans.insert({x,y});
    }
}
int main(){
    int x,y,t,p;
    cin>>n;
    cin>>p;
    for(int i = 0;i<p;i++){
        cin>>x>>y>>t;
        grid[x][y] = t; 
    }
    // for(auto c:grid){for(auto d:c)cout<<d<<" ";cout<<endl;}
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] ==  0)getans(i,j);
            if(grid[i][j] == -1)getans2(i,j);
        }
    }
    for(auto c:ans)cout<<c.first+1<<" "<<c.second+1<<endl;
    return 0;
}