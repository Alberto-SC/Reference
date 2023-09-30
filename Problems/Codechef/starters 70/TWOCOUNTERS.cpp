#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,m;
const int maxn = 100007;
vector<int> v(maxn,-1);

int dp[maxn][5];
int solve(int idx,int d){
    if(idx== n+1)return 0;
    int &x = dp[idx][d+2];
    if(x!=-1)return x;
    int ans = 0;


    if(v[idx]==1){
        if(d>0){
            if(d ==2)ans = 1+solve(idx+1,d-1);
            else ans = 1+max(solve(idx+1,d-1),solve(idx+1,d+1));
        }
        else{
            ans = max(solve(idx+1,+1),solve(idx+1,-1));
        }
    }   
    else if(v[idx]==2){
        if(d<0){
            if(d ==-2)ans = 1+solve(idx+1,d+1);
            else ans = 1+max(solve(idx+1,d-1),solve(idx+1,d+1));
        }
        else{
            ans = max(solve(idx+1,+1),solve(idx+1,-1));
        }
    } 
    else{
        if(d ==-2)ans = solve(idx+1,d+1);
        else if(d==2)ans = solve(idx+1,d-1);
        else ans = max(solve(idx+1,d-1),solve(idx+1,d+1));
    }
    return x = ans;
}

signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> t(m);
        vector<int> type(m);
        for(auto &c:t)cin>>c;
        for(auto &c:type)cin>>c;
        for(int i = 0;i<m;i++){
            v[t[i]] = type[i];

        }
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<5;j++){
                dp[i][j] = -1;
            }
        }
        cout<<max(solve(1,-1),solve(1,+1))<<endl;
        for(int i = 0;i<m;i++){
            v[t[i]] = -1;
        }
    }
    return 0;
}