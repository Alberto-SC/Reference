#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int T = 1,n,m;
const int maxn = 1007;
int dp[maxn][maxn];
vector<int> nxtR[maxn];
vector<int> nxtL[maxn];
vector<int> UP[maxn];
vector<int> DW[maxn];
bool vis[maxn][maxn];
int solve(int x,int y){
    int &X =  dp[x][y];
    if(X != -1)return X;

    // cout<<x<<" "<<y<<endl;
    int ans = 1;

    vis[x][y] = true;

    if(nxtR[x][y] != n+1 && !vis[x][nxtR[x][y]]) ans = max(ans,1+solve(x,nxtR[x][y]));
    if(nxtL[x][y] != -1 && !vis[x][nxtL[x][y]]) ans = max(ans,1+solve(x,nxtL[x][y]));
    if(UP[x][y] != -1 && !vis[UP[x][y]][y]) ans = max(ans,1+solve(UP[x][y],y));
    if(DW[x][y] != n+1 && !vis[DW[x][y]][y]) ans = max(ans,1+solve(DW[x][y],y));

    vis[x][y] = false;
    return X = ans;
}
int M[1007][1007];

signed main(){__
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>M[i][j];
        }
    }



    for(int i = 0;i<n;i++){
        nxtR[i].resize(n,n+1);
        nxtL[i].resize(n,-1);
        stack<int> st;

        for(int j = 0;j<n;j++){
            while(st.size() && M[i][st.top()]>=M[i][j]){
                nxtR[i][st.top()] = j;
                st.pop();
            }
            st.push(j);
        }   

        while(st.size()){
            st.pop();
        }

        for(int j = n-1;j>=0;j--){
            while(st.size() && M[i][st.top()]>=M[i][j]){
                nxtL[i][st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
    }
    for(int i = 0;i<n;i++){
        DW[i].resize(n,n+1);
        UP[i].resize(n,-1);
    }

    for(int i = 0;i<n;i++){
        stack<int> st;

        for(int j = 0;j<n;j++){
            while(st.size() && M[st.top()][i]>=M[j][i]){
                DW[st.top()][i] = j;
                st.pop();
            }
            st.push(j);
        }   

        while(st.size()){
            st.pop();
        }

        for(int j = n-1;j>=0;j--){
            while(st.size() && M[st.top()][i]>=M[j][i]){
                UP[st.top()][i] = j;
                st.pop();
            }
            st.push(j);
        }
    }

   

    int ans = 0;
    memset(dp,-1,sizeof(dp));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ans = max(ans,solve(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}