#include <bits/stdc++.h>
using namespace std;
const int maxn = 507;
int board[maxn][maxn];
int n,m;
bool check(int x,int y){
    // cout<<x<<" "<<y<<endl;
    int cu = 0,cd = 0,cl = 0,cr = 0;
    for(int i = x+1;i<n;i++){if(board[i][y] == 1)cd++;else break;}
    for(int i = x-1;i>=0;i--){if(board[i][y] == 1)cu++;else break;}
    for(int i = y-1;i>=0;i--){if(board[x][i] == 1)cl++;else break;}
    for(int i = y+1;i<m;i++){if(board[x][i] == 1)cr++;else break;}
    // cout<<cu<<" "<<cd<<" "<<cl<<" "<<cr<<endl;
    int xx= cl+cr+1,cont = 0;
    for(int i = 0;i<m;i++)if(board[x][i]==1)cont++;
    // if(x == 1 && y ==1)
        // cout<<xx<<" "<<cont<<endl;
    if(cont>xx)return false;
    xx = cu+cd+1;
    cont = 0;
    for(int i = 0;i<n;i++)if(board[i][y]==1)cont++;
    if(cont>xx)return false;
    if(cu>0 && cd>0 && cl>0 && cr>0 && board[x][y] == 1)return true;
    return false;
}
bool check2(int x,int y){
    for(int i = 0;i<n;i++){
        if(i == x)continue;
        for(int j = 0;j<m;j++){
            if(j == y)continue;
            if(board[i][j] == 1)return false;
        }
    }
    for(int i = x+1;i<n;i++)

    return true;
}
int main(){

    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;
            cin>>c;
            if(c == '*')
                board[i][j] = 1;
        
        }
    }
    // for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cout<<board[i][j]<<" \n"[j== m-1];
    bool flag = false;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            // cout<<check(i,j)<<" "<<endl;
            if(check(i,j) && !check2(i,j))return cout<<"No"<<endl,0;
            if(check(i,j))flag = true;
        }
    }
    cout<<"NO\0YES\0"+3*flag<<endl;
    return 0;
}