#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int DP[4007][4007][2];
int n,m;
vector<vector<int>> grid;
bool valid(int x,int y){
    if(x<0 ||y<0)return false;
    if(x>=n ||y>=m)return false;
    return true;
}
int solve(int a,int b,int x,int y,bool turn){
    if(x==n-1 && y==m-1){
        if(a>b)return 1;
        if(a==b)return -1;
        if(a<b)return 0;
    }

    int &dp = DP[a+2001][b+2001][turn];
    if(dp!=-1)return dp;
    int win1=-2,win2=-2,cont = 0;
    if(valid(x+1,y)){
        win1 = solve(a+(!turn?grid[x+1][y]:0),b+(turn?grid[x+1][y]:0),x+1,y,!turn),cont++;
    }
    if(valid(x,y+1))
        win2 = solve(a+(!turn?grid[x][y+1]:0),b+(turn?grid[x][y+1]:0),x,y+1,!turn),cont++;
    if(cont==1 && (win1 ==-1 ||win2 ==-1))dp = -1;
    else if(cont==2 && win1==-1 &&win2==-1)dp = -1;
    else if(!turn)(win1==1|| win2==1)?dp=1:dp=0;
    else if(turn)(win1==0 ||win2==0)?dp=0:dp=1; 
    return dp;
}

signed main(){__
    n = 2000,m =2000;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<"+";
        }
        cout<<endl;
    }
    else if(ans==0)cout<<"Aoki"<<endl;
    else if(ans==-1)cout<<"Draw"<<endl;
    return 0;
}  
