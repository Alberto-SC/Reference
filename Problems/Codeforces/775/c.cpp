#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,s,m;
    while(t--){
        cin>>n>>m;
        vector<int> CX[100007],CY[100007];
        int C;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>C;
                CX[C].push_back(i);
                CY[C].push_back(j);
            }
        }
        int ans = 0;
        for(int i = 1;i<=100000;i++){
            int ac = 0;
            sort(CX[i].begin(),CX[i].end());
            sort(CY[i].begin(),CY[i].end());
            for(int j = 0;j<CX[i].size();j++){
                ans+=(CX[i][j]*j)-ac;
                ac+=CX[i][j];
            }
            ac = 0;
            for(int j = 0;j<CY[i].size();j++){
                ans+=(CY[i][j]*j)-ac;
                ac+=CY[i][j];
            }
        }
        cout<<ans<<endl;
    }
}   