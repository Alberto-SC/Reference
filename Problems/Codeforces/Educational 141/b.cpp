#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int l = 1,r = n*n;
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i = 0;i<n;i++){
            if(i&1){
                int turn = n&1;
                for(int j = n-1;j>=0;j--){
                    if(turn)ans[i][j] = l++;
                    else ans[i][j] = r--;
                    turn^=1;
                }
            }
            else{
                for(int j = 0;j<n;j++){
                    if(j&1)ans[i][j] = l++;
                    else ans[i][j] = r--;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}