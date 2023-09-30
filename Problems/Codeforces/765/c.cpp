#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
const int inf = 1e15;
signed main(){__
    int t= 1,k,n,l;
    while(t--){
        cin>>n>>l>>k;
        vector<int> pos(n);
        vector<int> a(n);
        for(auto &c:pos)cin>>c;
        for(auto &c:a)cin>>c;
        int DP[501][501];
        for(int i = 0;i<=n;i++)
            DP[0][i] = 0;
        pos.push_back(l);
        for(int i = 1;i<=n;i++)
            for(int j = 0;j<=k;j++)
                DP[i][j] = inf;

        for(int i = 1;i<=n;i++){ 
            for(int j = 0;j<=k;j++){
                for(int x = 0;x<=j;x++){
                    if((i-1)-x<0)break;
                    DP[i][j] = min(DP[i][j],DP[(i-1)-x][j-x] + (a[(i-1)-x]*(pos[i]-pos[(i-1)-x])));
                }    
            }
        }
        int ans = 1e16;
        for(int i = 0;i<=k;i++)
            ans = min(ans,DP[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
