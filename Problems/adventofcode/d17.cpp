#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;


const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1,+0,+0,+1,-1,-1,+1,-1,+1,+0,+0,+1,-1,-1,+1,-1,+1,+0,+0};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1,-1,+1,+0,+0,+1,+1,-1,-1,-1,+1,+0,+0,+1,+1,-1,-1,+0,+0}; 
const int fz[]={+0,+0,+0,+0,+0,+0,+0,+0,+1,+1,+1,+1,+1,+1,+1,+1,-1,-1,-1,-1,-1,-1,-1,-1,+1,-1};
char grid[51][51][51][51];
bool valid(int x,int y,int z,int w){
    if(z>=51 || x>=51||y>=51||w>51)return false;
    if(x<0 || y<0 || z<0||w<0)return false;
    return true;
}
int main(){
    string s;
    vector<string> tablero;
    while(cin>>s){
        tablero.push_back(s);
    }
    int n = tablero.size();
    int m = tablero[0].size();
    int l = 0,r = 50;
    for(int i = l;i<r;i++)
        for(int j = l;j<r;j++)
            for(int k = l;k<r;k++)
                for(int p = l;p<=r;p++)
                    grid[i][j][k][p] = '.';

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            grid[25][25+i][25+j][25] = tablero[i][j];

    for(int ii = 0;ii<6;ii++){
        char copy[51][51][51][51];
        for(int i =l;i<=r;i++){
            for(int j = l;j<=r;j++){
                for(int k = l;k<=r;k++){
                    for(int p = l;p<=r;p++){
                        int cont = 0;
                        for(int x1 = -1;x1<2;x1++){
                            for(int y1 = -1;y1<2;y1++){
                                for(int z1= -1;z1<2;z1++){
                                    for(int w1 = -1;w1<2;w1++){
                                        int nx = i+x1;
                                        int ny = j+y1;
                                        int nz = k+z1;
                                        int nw = p+w1;
                                        if(nx == i && ny == j && nz== k && nw == p)continue;
                                        if(valid(nx,ny,nz,nw) && grid[nx][ny][nz][nw]== '#')cont++;
                                    }
                                }
                            }
                        }
                        // cout<<i<<" "<<j<<" "<<k<<" "<<cont<<endl;
                        if(grid[i][j][k][p]== '#' && (cont<2 || cont >3)){
                            // cout<<i<<" "<<j<<" "<<k<<" "<<cont<<endl;
                            copy[i][j][k][p] = '.';
                        }
                        else if(grid[i][j][k][p]== '#' && (cont == 3 || cont == 2))copy[i][j][k][p] = '#';
                        else if(grid[i][j][k][p] == '.' && cont ==3){
                            // cout<<i<<" "<<j<<" "<<k<<endl;
                            copy[i][j][k][p] = '#';
                        }
                        else copy[i][j][k][p] = '.';
                    }
                }
            }
        }
        int cont = 0;
        for(int i = l;i<=r;i++){
            for(int j = l;j<=r;j++){
                for(int k = l;k<=r;k++){
                    for(int p = l;p<=r;p++){
                        if(copy[i][j][k][p]== '#')cont++;
                        grid[i][j][k][p] = copy[i][j][k][p];
                    }
                }
            }
        }
        cout<<cont<<endl;   
    }
    int ans = 0;
    for(int i = l;i<=r;i++)
        for(int j = l;j<=r;j++)
            for(int k = l;k<=r;k++)
                for(int p = l;p<=r;p++)
                    if(grid[i][j][k][p] == '#')ans++;
    cout<<ans<<endl;
    return 0;
}