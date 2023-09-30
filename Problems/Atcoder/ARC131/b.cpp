#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
signed main(){__
  int n,m;
  cin>>n>>m;
  char M[n][m];
  for(int i = 0;i<n;i++)
      for(int j = 0;j<m;j++)
          cin>>M[i][j];

  auto valid = [&](int x,int y){
    if(x<0 || y<0 )return false;
    if(x>=n || y>=m)return false;
    return true;
  };

  vector<int> fx = {+1,-1,+0,+0};
  vector<int> fy = {+0,+0,+1,-1};
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      if(M[i][j]!='.')continue;
      vector<bool> used(5+1);
      for(int k = 0;k<4;k++){
        int nx = i + fx[k];
        int ny = j + fy[k];
        if(valid(nx,ny) && M[nx][ny]!= '.')
          used[M[nx][ny]-'0'] = true;
      }
      for(int k = 1;k<=5;k++)
        if(!used[k])M[i][j] = char(k+'0');
    }
  }
  for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
          cout<<M[i][j]; 
      }
      cout<<endl;
  }

  return 0;
}
