#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<string> M(n);
        for(auto &c:M)cin>>c;
        vector<vector<bool>> vis(n,vector<bool>(m));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(M[i][j] == '.')continue;
                int cont1 = 0,cont2 = 0;
                int x =i,y = j;
                while(x>=0 && y>=0){
                    if(M[x][y]!='*')break;
                    cont1++;
                    x--,y--;
                }
                x = i,y = j;
                while(x>=0 && y<m){
                    if(M[x][y]!='*')break;
                    cont2++;
                    x--,y++;
                }
                int d = min(cont1,cont2),aux = d;
                if(d-1>=k){
                    x = i,y = j;
                    while(d--){
                        vis[x][y] = true;
                        x--,y--;
                    }
                    x = i,d = aux,y = j;
                    while(d--){
                        vis[x][y] = true;
                        x--,y++;
                    }
                }
            }
            
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(M[i][j] =='*' && !vis[i][j]){
                    flag = false;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
