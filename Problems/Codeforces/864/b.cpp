#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> rotate(vector<vector<int>> &M){
    int n = M.size();
    vector<vector<int>> rot(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            rot[i][j] = M[n-j-1][i];
        }
    }
    return rot;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int k;
        cin>>n>>k;
        vector<vector<int>> M(n,vector<int>(n));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
            }
        }

        int need = 0;
        int same = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == (n-i-1) && j == (n-j-1))
                    same++;
                else 
                    need+=M[i][j]!= M[n-i-1][n-j-1];
            }
        }
        need/=2;

        if(need<=k &&  (n&1 || (k-need)%2 == 0)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}