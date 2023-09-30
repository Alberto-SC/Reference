#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1007][2];
int n,m,x,y;
vector<int> A(1007);
vector<int> B(1007);
int solve(int idx,int last){
    if(idx>=m)
        return 0;
    int &res = dp[idx][last];
    if(res !=-1)return res;
    if((idx+x)-1>=m)return res = 1e18;
    int need = 0,L = (idx+x)-1,ans = 1e18,R = idx+y;
    for(int i = idx;i<L;i++)
        need+=last?A[i]:B[i];
    for(int i = L;i<min(m,R);i++){
        need+=last?A[i]:B[i];
        ans = min(ans,solve(i+1,!last)+need);
    }
    return res= ans;
}

signed main(){__
    cin>>n>>m>>x>>y;
    memset(dp,-1,sizeof(dp));
    vector<vector<char>> M(n,vector<char>(m));
    for(int i = 0;i<n;i++){ 
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
            A[j]+= M[i][j] =='#';
            B[j]+= M[i][j] =='.';
        }
    }
    cout<<min(solve(0,1),solve(0,0))<<endl;
    return 0;
}  
