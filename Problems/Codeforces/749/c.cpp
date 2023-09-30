#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> dp;
vector<vector<int>> bit2D;
vector<vector<char>> grid;

int N,M;
int sum2D(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit2D[i][j];
    return ret;
}
int sum2D(int x0,int y0,int x,int y){
    return sum2D(x,y)-sum2D(x,y0-1)-sum2D(x0-1,y)+sum2D(x0-1,y0-1);
}

void add2D(int x, int y, int delta) {
    for (int i = x; i < N; i = i | (i + 1))
        for (int j = y; j < M; j = j | (j + 1))
            bit2D[i][j] += delta;
}


vector<int> fx = {-1,+0};
vector<int> fy = {+0,-1};

bool solve(int x,int y){
    if(x==0 || y== 0){
        return dp[x][y] = 1;    
    }
    if(dp[x][y]!=-1)return dp[x][y];
    int ans = 0;
    for(int i = 0;i<2;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(grid[nx][ny]=='.')
            ans +=solve(nx,ny);
    }
    if(ans>=1)ans = 1;
    return dp[x][y] = ans;
}

signed main(){__
	int t= 1;
    cin>>N>>M;
    grid.resize(N,vector<char>(M));
    dp.resize(N,vector<int>(M,-1));
    bit2D.resize(N,vector<int>(M));

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='X')
                dp[i][j] = 0;
        }
    }
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            if(grid[i][j]=='.')solve(i,j);
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            if(grid[i][j]=='.' && dp[i][j]== 0)   add2D(i,j,1); 
    int q,l,r;
    cin>>q;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++) 
            cout<<grid[i][j]<<" \n"[j==M-1];
    cout<<endl;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++) 
            cout<<dp[i][j]<<" \n"[j==M-1];
    cout<<endl;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++) 
            cout<<sum2D(i,j,i,j)<<" \n"[j==M-1];
    while(q--){
        cin>>l>>r;
        int s = sum2D(0,l-1,N-1,r-1);
        cout<<s<<endl;
        if(s)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}  
