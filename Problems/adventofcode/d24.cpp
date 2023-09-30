#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
int fxy[6][2] = {{-1,0},{-1,+1},{ 0,+1},{+1,0},{+1,-1},{0,-1}};

bool grid[1000][1000];
void print(){
    for(int i = 495;i<505;i++){
        for(int j = 495;j<505;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool valid(int x,int y){
    if(x>=1000 || y>=1000)return false;
    if(x<0 || y<0)return false;
    return true;
}
int main(){
    string s;
    vector<string> tiles;
    while(cin>>s){
        tiles.push_back(s);
    }
    int n = tiles.size();
    for(int i = 0;i<n;i++){
        int x = 500,y = 500;
        int cont = 0;
        // cout<<tiles[i]<<endl;
        for(int j = 0;j<tiles[i].size();j++){
            // cout<<tiles[i][j]<<" ";
            if(tiles[i][j] == 'e'){
                x+=fxy[5][0];
                y+=fxy[5][1];
            }
            else if(tiles[i][j]== 'w'){
                x+=fxy[2][0];
                y+=fxy[2][1];
            }
            else if(tiles[i][j]== 's'){
                if(tiles[i][j+1]== 'w'){
                    x+=fxy[3][0];
                    y+=fxy[3][1];
                }
                else{
                    x+=fxy[4][0];
                    y+=fxy[4][1];
                }
                j++;
            }
            else if(tiles[i][j] =='n'){
                if(tiles[i][j+1] == 'w'){
                    x+=fxy[1][0];
                    y+=fxy[1][1];
                }
                else{
                    x+=fxy[0][0];
                    y+=fxy[0][1];
                }
                j++;
            }
        }
        grid[x][y] = !grid[x][y];
    }
    int ans  = 0;
    for(int i = 0;i<1000;i++){
        for(int j = 0;j<1000;j++){
            if(grid[i][j])ans++;
        }
    }
    cout<<ans<<endl;


    for(int i = 0;i<100;i++){
        bool nw[1000][1000];
        for(int j = 0;j<1000;j++)
            for(int k = 0;k<1000;k++)
                nw[j][k] = grid[j][k];
        // print();
        for(int j = 0;j<1000;j++){
            for(int k = 0;k<1000;k++){
                int cont = 0;
                for(int z = 0;z<6;z++){
                    int nx = j+fxy[z][0];
                    int ny = k+fxy[z][1];
                    if(valid(nx,ny)&& grid[nx][ny])
                        cont++;
                }
                if(grid[j][k] && (cont ==0 || cont>2))nw[j][k] = false;
                if(!grid[j][k] && cont == 2)nw[j][k] = true;
            }
        }
        int cont = 0;
        for(int j = 0;j<1000;j++){
            for(int k = 0;k<1000;k++){
                if(nw[j][k])cont++;
                grid[j][k] = nw[j][k];
            }
        }
        cout<<cont<<endl;
    }
}  
