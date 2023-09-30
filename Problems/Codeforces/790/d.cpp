#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int n,m;

 bool valid (int x,int y){
    if(x<0 || y<0 )return false;
    if(x>=n|| y>=m)return false;
    return true;
}
signed main(){__
  int t;
  cin>>t;
  while(t--){
    cin>>n>>m;
    int M[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }
    int best = 0;

   
    for(int i = 0;i<n;i++){
        for(int j  = 0;j<m;j++){
            int x = i,y = j;
            int ans = 0;
            ans+=M[x][y];
            while(1){
                x++;
                y++;
                if(!valid(x,y))break;
                ans+=M[x][y];
            }
        
            x = i,y = j;
            while(1){
                x++;
                y--;
                if(!valid(x,y))break;
                ans+=M[x][y];
            }
            x = i,y = j;
            while(1){
                x--;
                y++;
                if(!valid(x,y))break;
                ans+=M[x][y];
            }
            x = i,y = j;
            while(1){
                x--;
                y--;
                if(!valid(x,y))break;
                ans+=M[x][y];
            }
            best = max(best,ans);
        }
    }
    cout<<best<<endl;

  }
  return 0;
}
