#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(vector<vector<int>> M){
    int n = M.size();
    int m = M[0].size();
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m-1;j++){
            int cont = 0;
            cont +=M[i][j];
            cont +=M[i][j+1];
            cont +=M[i+1][j];
            cont +=M[i+1][j+1];
            if(cont!=2)return false;
        }
    }
    return true;
}

signed main(){
    int T = 1,n;
    while(T--){
        int n = 5,m = 5;
        for(int i = 2;i<=n;i++){
            for(int j = 2;j<=m;j++){
                int ans = 0;
                for(int mask = 0;mask<(1<<(i*j));mask++){
                    vector<vector<int>> M(n,vector<int> (m));
                    int x = 0,y = 0;
                    // bitset<25> bs(mask);
                    cout<<bs<<endl;
                    for(int k = 0;k<(i*j);k++){
                        M[x][y] = (mask>>k)&1;
                        y++;
                        if(y == m)x++,y = 0;
                    }
                    if(check(M))ans++;
                }
                cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
    }
    return 0;
}