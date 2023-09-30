#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t = 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        vector<vector<int>> grid2(m,vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cin>>grid2[i][j];
            }
        }
        int x;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[0][0] ==grid[i][j]){
                    x = i;
                    break;
                }
            }
        }
        vector<int> pos(m*n+1);
        for(int i = 0;i<m;i++){
            pos[grid[x][i]] = i;
        }

        sort(grid2.begin(),grid2.end(), [&](vector<int> A,vector<int> B){
            return pos[A[0]]<pos[B[0]];
        });


        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<grid2[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

