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
        bool flag = true;
        for(int i = 0;i<n;i++){
            bool f = false,f2 = false;;
            for(int j = 0;j<n;j++){
                if(M[i][j]==0)f = true;
                if(M[j][i]==0)f2 = true;
            }
            flag&=f;
            flag&=f2;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
