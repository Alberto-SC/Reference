#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int n,m;
int dp[1<<11][1007];

bool occupied(int i, int q){
    return q&(1 << (i-1));
}

void search(int i, int j, int p, int q){
    if(i == n+1){
        dp[p][j+1] += dp[q][j];
        return;
    }

    if(occupied(i, q)){
        search(i+1, j, p, q);
        return;
    }
    if(i+1 <= n && !occupied(i+1, q)){
        search(i+2, j, p, q);
    }
    if(j+1 <= m){
        search(i+1, j, p^(1 << (i-1)), q);
    }
}

int main(){__
    cin>>n>>m;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; //Initial condition
    for(int j = 1; j < m; j++){
        for(int q = 0; q < (1<<n); q++){
            search(1, j, 0, q);
        }
    }
    cout<<dp[0][m]<<endl;
}
