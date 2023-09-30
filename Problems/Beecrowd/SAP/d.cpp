#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


void rotateM(vector<vector<char>> &c){
    int n = 3;
    for (int i=0;i<n/2;i++) { 
        for (int j=i;j<n-i-1;j++) { 
                int temp=c[i][j]; 
                c[i][j]=c[n-1-j][i]; 
                c[n-1-j][i]=c[n-1-i][n-1-j]; 
                c[n-1-i][n-1-j]=c[j][n-1-i]; 
                c[j][n-1-i]=temp; 
        } 
    }
}

signed main(){__
    int n,m;
    cin>>n>>m;
    char grid[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    auto f = [&](int x,int y){
        return (x*m)+y;
    };
    map<int,vector<int>> mp[4];
    for(int x = 1;x<=3;x++){
        for(int i = 0;i<=n-3;i++){
            for(int j = 0;j<=m-3;j++){
                int hash = 0;
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        if(grid[i+k][j+l]!=char(x+'0'))continue;
                        hash+=1<<((k*3)+l);
                    }
                }
                cout<<"X: "<<x<<" "<<f(i,j)<<" "<<hash<<" "<<i<<" "<<j<<endl;
                mp[x][hash].push_back(f(i,j));
            }  
        }
    }
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        vector<vector<char>> G(3,vector<char> (3));
        
        for(int a = 0;a<3;a++)
            for(int b = 0;b<3;b++)
                cin>>G[a][b];
        map<int,int> mp2;
        int ans = 0;
        for(int rot = 0;rot<1;rot++){
            cout<<"ROTATION: "<<rot<<endl;
            for(int x = 1;x<=3;x++){
                int hash = 0;
                for(int a = 0;a<3;a++){
                    for(int b = 0;b<3;b++){
                        if((G[a][b]-'0')==x){
                            hash+=1<<((a*3)+b);
                        }
                    }
                }
                cout<<"X: "<<x<<" "<<hash<<endl;
                for(auto c:mp[x][hash]){
                    cout<<c<<endl;
                    mp2[c]++;
                }
            }
            for(auto c:mp2){
                // cout<<c.first<<" "<<c.second<<endl;
                if(c.second==3)
                ans++;
            }
            // cout<<endl;
            rotateM(G);
        }
        cout<<ans<<endl;
    }
}   