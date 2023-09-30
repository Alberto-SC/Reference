#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int n = 8;
        vector<string> S(n);
        for(auto &c:S)cin>>c;
        int colum = -1,row = -1;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(S[i][j]>='a' && S[i][j]<='z'){
                    colum = j;
                    row = i;
                    break;
                }
            }
            if(colum!=-1)break;
        }
        string ans = "";
        while(row<n){
            if(S[row][colum]<'a' || S[row][colum]>'z')break;
            ans+=S[row][colum];
            row++;
        }
        cout<<ans<<endl;


    }
    return 0;
}