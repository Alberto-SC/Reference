#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int x = 0,y = 0;
    cin>>n>>m;
    int dir = 2;
    int ind[n][m];
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>ind[i][j];
        }
    }
    if(x == m-1 && y == n-1)return cout<<"llegaste"<<endl,0;
    int count  = 0;
    while(x<m && y<n && x>=0 && y>=0){
        count++;
        if(count>n*m)break;
        // cout<<y<<" "<<x<<endl;  
        if(ind[y][x] == 0){
            if(dir==2)x++;
            else if(dir==1)y--;
            else if(dir==3)y++;
            else if(dir==4)x--;
        }
        else if(ind[y][x] == 1){
            if(dir==1)x++,dir=2;
            else if(dir==2)y++,dir=3;
            else if(dir==3)x--,dir=4;
            else if(dir==4)y--,dir=1;

        }
        else if(ind[y][x] == 2){
            if(dir==1)x--,dir=4;
            else if(dir==2)y--,dir=1;
            else if(dir==3)x++,dir=2;
            else if(dir==4)y++,dir=4;

        }
        else if(ind[y][x] == 3){
            if(dir ==1)y++,dir =3;
            else if(dir ==2)x--,dir =4;
            else if(dir ==3)y--,dir =1;
            else if(dir ==4)x++,dir =2;
        }
        if(x == m-1 && y== n-1)break;
    }
    if(x == m-1&& y==n-1)cout<<"llegaste"<<endl;
    else cout<<"te perdiste"<<endl;
    return 0;
}