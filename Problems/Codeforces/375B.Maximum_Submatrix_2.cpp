#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,m;
    cin>>n>>m;
    char matrix[n][m];
    vector<vector<int>> cols(m,vector<int>(m+1));
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>matrix[i][j];
    for(int i = 0;i<n;i++){
        int cont = 0;
        for(int j = m-1;j>=0;j--){
            if(matrix[i][j] == '1')cont++;
            else cont = 0;
            cols[j][cont]++;
        }
    }
    int ans = 0;
    for(int i = 0;i<m;i++){
        int cont = 0;
        for(int j =m;j>=0;j--){
            for(int k = 0;k<cols[i][j];k++){
                ans = max(ans,(cont+1)*j);
                cont++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}