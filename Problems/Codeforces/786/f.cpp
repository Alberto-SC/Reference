#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,q;
    cin>>n>>m>>q;
    vector<string> M(n);
    int cont = 0;
    for(int i = 0;i<n;i++){
        cin>>M[i];
        for(int j = 0;j<m;j++){
            cont+=M[i][j]=='*';
        }
    }
    int x = 0,y = 0;
    int good = 0;
    for(int i = 0;i<cont;i++){
        if(M[x][y]=='*')good++;
        x++;
        if(x==n)x = 0,y++;
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        a--,b--;
        if(M[a][b]=='*'){
            cont--;
            if(b<y)good--;
            else if(b == y && a<x)good--;
            
            if(x==0){
                y--;
                x = n-1;
            }
            else x--;

            M[a][b] = '.';
            if(M[x][y]=='*')good--;
            

        }
        else{
            cont++;
            
            if(M[x][y]=='*')good++;
            M[a][b] = '*';

            if(x ==n-1){
                x = 0;
                y++;
            }
            else x++;

            if(b<y)good++;
            else if(b==y && a<x)good++;
        }
        cout<<cont-good<<endl;
    }   

    return 0;
}