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
        bool f = true;
        vector<vector<int>> M(n,vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
            }
        }
        int ans = 0;
        for(int i =n-1;i>=0;i--){
            if(M[0][i]!= i+1){
                if(ans%2==0)
                    ans++;
            }
            else if(ans&1)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
