#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

unordered_map<pair<pair<int,int>,int >,int> mp;
int n;
bool valid(int x,int y){
    if(x>=n || y>=n)return false;
    return true;
}

int M[21][21];
int solve(int i,int j,int xo){
    if(i == n-1 && j == n-1){
        if(xo)return 0;
        else return 1;
    }
    if(mp.count({{i,j},xo}))return mp[{{i,j},xo}];
    int ans = 0;
    if(valid(i+1,j))
        ans +=solve(i+1,j,xo^M[i+1][j]);
    if(valid(i,j+1))
        ans +=solve(i,j+1,xo^M[i][j+1]);

    return mp[{{i,j},xo}] = ans;
}


signed main(){__
    int T = 1;
    while(T--){
        cin>>n;
        for(int i  = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
            }
        }
        cout<<solve(0,0,M[0][0])<<endl;
    }
    return 0;
}
