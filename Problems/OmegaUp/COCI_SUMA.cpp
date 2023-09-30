#include <iostream>
#include <string>
using namespace std;
int grid[70][70];
int mx[] = { 1, 0, -1, 0};
int my[] = { 0, 1,  0,-1};
bool vis[70][70];

int dfs(int x,int y,int n){
	vis[x][y] = true;
	int sigx,sigy,tam = 1;
	for(int i = 0;i<4;i++){
		sigx = x+mx[i];
		sigy = y+my[i];
		if(sigx >= 0&& sigx<n && sigy<n && sigy>=0 && grid[sigy][sigx] == grid[x][y] &&!vis[sigy][sigx]){
		tam += dfs(sigx,sigy,n);
		}
	}
	return tam;
	
}
int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0);
	int n,h,NC = 0;
	cin>> n;

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){	
			cin>>h;
			grid[i][j] = h;
			vis[i][j] = false;
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){	
			cin>>h;
			grid[i][j] += h;
			}
		}
		for(int u = 0; u<n;u++){
			for(int v = 0;v<n;v++){
				if(!vis[u][v]){
					n= dfs(u,v,n);
					if(NC < n)NC = n;	 
				}
			}
		}
		cout<<NC;
	}
	

