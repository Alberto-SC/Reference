#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A) for(auto c:A){print(c);}
vector<vector<int>> prefix[5];

vector<vector<int>> prefixSum2D(vector<vector<int>> a,int R,int C){
    vector<vector<int>> psa(R,vector<int> (C));
    psa[0][0] = a[0][0];
    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1]
                        - psa[i - 1][j - 1] + a[i][j];
    }

    return psa;
}

int sum2D(int who,int x0,int y0,int x1,int y1){
    int l = 0,u= 0,d= 0;
    if(y0-1>=0)
        l = prefix[who][x1][y0-1];
    if(x0-1>=0)
        u = prefix[who][x0-1][y1];
    if(x0 && y0)
        d = prefix[who][x0-1][y0-1];
    return prefix[who][x1][y1]-l-u+d;
}

int n,m;
int check(int x0,int y0,int x1,int y1){
    int cont = 0;
    for(int i = 0;i<5;i++){
        if(sum2D(i,x0,y0,x1,y1))
            cont++;
    }
    return cont;
}


signed main(){__
    cin>>n>>m;
    char grid[n][m];
    for(int i = 0;i<5;i++)
        prefix[i].resize(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]== 'W')
                prefix[0][i][j] = 1;
            if(grid[i][j]== 'A')
                prefix[1][i][j] = 1;
            if(grid[i][j]== 'L')
                prefix[2][i][j] = 1;
            if(grid[i][j]== 'D')
                prefix[3][i][j] = 1;
            if(grid[i][j]== 'O')
                prefix[4][i][j] = 1;                
        }
    }
    prefix[0] = prefixSum2D(prefix[0],n,m);
    prefix[1] = prefixSum2D(prefix[1],n,m);
    prefix[2] = prefixSum2D(prefix[2],n,m);
    prefix[3] = prefixSum2D(prefix[3],n,m);
    prefix[4] = prefixSum2D(prefix[4],n,m);

    int ans = n*m+3;

    if(n<m){
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int l = 0,r = 0;
                while(r<m){
                    while(check(i,l+1,j,r)==5){
                        l++;
                    }
                    if(check(i,l,j,r)==5)ans =min(ans,((j-i)+1)*((r-l)+1));
                    r++;
                }
            }
        }
    }
    else{
        for(int i = 0;i<m;i++){
            for(int j = i;j<m;j++){
                int l = 0,r = 0;
                while(r<n){
                    while(check(l+1,i,r,j)==5){
                        l++;
                    }
                    if(check(l,i,r,j)==5)ans =min(ans,((j-i)+1)*((r-l)+1));
                    r++;
                }
            }
        }
    }
    if(ans == n*m+3)cout<<"impossible"<<endl;
    else cout<<ans<<endl;
  
}   