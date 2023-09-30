#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        char M[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = M[n - 1 - j][i];
                int cont = 0;
                cont+=M[i][j] == '1';
                cont+=M[n-1-j][i]=='1';
                cont+=M[n-1-i][n-j-1] == '1';
                cont+=M[j][n-1-i] == '1';
                ans+=min(cont,4-cont);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}  
