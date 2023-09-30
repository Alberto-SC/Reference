#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> M(n,vector<int>(m));
        if(n == 1 && m == 1){
            (n+=n)-=n;
        }
        else if(n == 1|| m == 1){
            if(n == 1){
                for(int i = 0;i<m;i++)
                    M[0][i] = i+2;
            }
            if(m == 1){
                for(int i = 0;i<n;i++)
                    M[i][0] = i+2;
            }
        }
        else{
            for(int j = n+1;j<=n+m;j++){
                int start = j;
                int aux = start;
                for(int x = 0;x<n;x++){
                    M[x][j-(n+1)] = start;
                    start+=aux;
                }
            }
        }
        
        for(auto c:M){
            for(auto d:c)cout<<d<<" ";
            cout<<endl;
        }
    }
    return 0;
}  
