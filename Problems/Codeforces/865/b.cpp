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
        int r = 2*n;
        int l = n;
        vector<int> ans[2];
        ans[0].resize(n);
        ans[1].resize(n);
        ans[0][0] = r--;
        ans[1][n-1] = r--;

        for(int i = 0;i<(n/2)-1;i++){
            if(i&1){
                ans[1][i] = r--;
                ans[0][i+1] = r--;

                ans[1][n-i-2] = r--;
                ans[0][n-i-1] = r--;
            }
            else{
                ans[1][i] = l--;
                ans[0][i+1] = l--;

                ans[1][n-i-2] = l--;
                ans[0][n-i-1] = l--;
            }
        }

        if(l == 0){
            ans[1][(n/2)-1] = r--;
            ans[0][(n/2)] = r--;
        }
        else{
            ans[1][(n/2)-1] = l--;
            ans[0][(n/2)] = l--;
        }

        for(auto c:ans){
            for(auto d:c)cout<<d<<" ";
            cout<<endl;
        }
    }
    return 0;
}