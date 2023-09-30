#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int R,C;
int A[507][507];
int B[507][507];
const int inf = 1e15;
int DP[507][507];
int solve(int x,int y){
    cout<<x<<" "<<y<<endl;
    if(x==R && y == C)return 0;
    if(y<1|| x<1)return inf;
    if(x>R|| y>C)return inf;
    int &ans = DP[x][y];
    if(ans!=-1)return x;
    int res = inf;
    if(y<C)
        res = min(res,solve(x,y+1)+A[x][y]);
    if(x<R)
        res = min(res,solve(x+1,y)+B[x][y]);
    if(y>1)
        res = min(res,solve(x,y-1)+A[x][y-1]);
    for(int i = 1;i<x;i++)
        res = min(res,solve(x-i,y)+1+i);
    return ans =res;
}

signed main(){__
    cin>>R>>C;
    memset(DP,-1,sizeof(DP));
    for(int i = 1;i<=R;i++)
        for(int j = 1;j<=C-1;j++)
            cin>>A[i][j];
    
    for(int i = 1;i<=R-1;i++)
        for(int j = 1;j<=C;j++)
            cin>>B[i][j];
    
    cout<<solve(1,1)<<endl;
    return 0;
}  
