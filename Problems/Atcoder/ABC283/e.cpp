#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int M[1007][1007];
int dp[1007][2][2];

int n,m;
vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};

bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>=m)return false;
    return true;
}
const int inf = 1e15;

int solve(int idx,int flip = 0,int need = 0){
    if(idx == n)return !need;
    

    int &x = dp[idx][flip][need];
    if(x!=-1)return x;

    int ans = inf;
    bool nd1 = false,nd2 = false;
    for(int i = 0;i<m;i++){
        int cont = 0,vl = 0;
        for(int j = 0;j<4;j++){
            int nx = idx+fx[j];
            int ny = i+fy[j];

            if(valid(nx,ny)){
                vl++;
                if(nx == idx-1)cont+=M[nx][ny]^flip;
                else cont+= M[nx][ny] == M[idx][i];
            }
        }
        if(cont == 0)nd1 = true;
        if(cont == vl)nd2 = true;
    }

    if(need && nd2)ans = 1+solve(idx+1,1,1);
    else if(need)ans = 1+solve(idx+1,1,0);
    else if(nd1){
        ans = 1+solve(idx+1,1,nd2);
        
        ans = min(ans,solve(idx+1,0,1));
    }
    else{
        ans = solve(idx+1,0,0);
        ans = min(ans,1+solve(idx+1,1,0));
    }
    return x= ans;
}   

signed main(){__
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0,0);
    if(ans >n)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}