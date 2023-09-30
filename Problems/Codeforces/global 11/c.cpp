#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int r;
vector<int> grid[507][507];
int DP[507][507][];

int mx = 0;
int solve(int x,int y,int t,int c = 0){
    if(t>mx)return x;

    int &x = DP[x][y][t];

}
int main(){__
    int t = 1,n;
    cin>>r>>n;
    
    for(int i = 0;i<n;i++){
        cin>>t>>x>>y;
        x--,y--;
        mx = t;
        grid[x][y].push_back(t);
    }
    solve(0,0,0);
    return 0;
}

