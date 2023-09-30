#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

char M[100][100];
bool vis[100][100];
int tme[100][100];
signed main(){
    int R,C,E;
    while(1){ 
        cin>>R>>C>>E;
        bool loop = false;
        if(R==0 && C==0 && E==0)break;
        int x  = 0,y = E-1;
        for(int i = 0;i<R;i++){
            for(int j = 0;j<C;j++){
                cin>>M[i][j];
                vis[i][j] = false;
                tme[i][j] = 0;
            }
        }
        int cont = 0,sz,timeB;
        while(true){
            cont++;
            if(M[x][y]=='W'){
                if(y-1<0)break;
                else if(vis[x][y-1]){
                    loop = true;
                    sz = cont-tme[x][y];
                    timeB = tme[x][y-1];
                    break;
                }
                else{
                    vis[x][y] = true;
                    tme[x][y] = cont;
                }
                y--;
            }
            else if(M[x][y]=='N'){
                if(x-1<0)break;
                else if(vis[x-1][y]){
                    loop = true;
                    sz = cont-tme[x][y];
                    timeB = tme[x-1][y];
                    break;
                }
                else{
                    vis[x][y] = true;
                    tme[x][y] = cont;
                }
                x--;
            }
            else if(M[x][y]=='E'){
                if(y+1>=C)break;
                else if(vis[x][y+1]){
                    loop = true;
                    sz = cont-tme[x][y];
                    timeB = tme[x][y+1];
                    break;
                }
                else{
                    vis[x][y] = true;
                    tme[x][y] = cont;
                }
                y++;
            }
            else if(M[x][y]=='S'){
                if(x+1>=R)break;
                else if(vis[x+1][y]){
                    loop = true;
                    sz = cont-tme[x][y];
                    timeB = tme[x+1][y];
                    break;
                }
                else{
                    vis[x][y] = true;
                    tme[x][y] = cont;
                }
                x++;
            }
        }
        if(loop)cout<<timeB-1<<" step(s) before a loop of "<<sz-(timeB-1)<<" step(s)"<<endl;
        else cout<<cont<<" step(s) to exit"<<endl; 
    }
    return 0;
}  
