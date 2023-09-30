#include <iostream>
#include <string>
using namespace std;
char grid[307][307];
int mx[] = { 1, 0, -1, 0};
int my[] = { 0, 1, 0, -1};
bool vis[307][307];

int dfs(int x,int y,int c,int r){
	vis[y][x] = true;
	int sigx,sigy,tam=1;
	for(int i = 0;i<4;i++){
		sigx = x+mx[i];
		sigy = y+my[i];
		if(sigx>=0&& sigx<c && sigy<r && sigy>=0 && grid[sigy][sigx] =='1' &&!vis[sigy][sigx]){
		tam += dfs(sigx,sigy,c,r);
		}
	}
	return tam;
	
}
int main(){
	int r,c;
    cin>>r>>c;
    for(int k = 0;k<307; k++){
        for(int l = 0;l<307;l++){
            vis[k][l] = false;
            grid[k][l] = '0';
        }
    }
    char s;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>s;
            if(s=='X')
            grid[i][j] = '1';
        }
    }
    int mx = 0,n,mn = 1e9;
    for(int u = 0; u<r;u++){
        for(int v = 0;v<c;v++){
            if(!vis[u][v] && grid[u][v]=='1'){
                n= dfs(v,u,c,r);
                mx = max(mx,n);
                mn = min(mn,n); 
            }
        }
    }
    if(mn== 1000000000)mn = 0;
    cout<<mx<<endl<<mn<<endl;
	
}
