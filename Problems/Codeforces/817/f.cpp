#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

char M[57][57];
vector<int> fx = {-1,-1,-1,+0,+0,+1,+1,+1};
vector<int> fy = {-1,+0,+1,-1,+1,-1,+0,+1};
bool vis[57][57];

int n,m;
bool valid(int x,int y){
  if(x<0 || y<0)return false;
  if(x>= n || y>= m)return false;
  return true;
}

int cont = 0;
vector<int> xs;
vector<int> ys;
void dfs(int x,int y){
  vis[x][y] = true;
  xs.push_back(x);
  ys.push_back(y);
  cont++;
  for(int i = 0;i<8;i++){
    int nx = fx[i]+x;
    int ny = fy[i]+y;
    if(valid(nx,ny) && !vis[nx][ny] && M[nx][ny]== '*')
      dfs(nx,ny);
  }
}

signed main(){
  int T = 1;
  cin>>T;
  while(T--){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        cin>>M[i][j];
        vis[i][j] = false;
      }
    }
    bool flag = true;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        if(M[i][j]=='.')continue;
        if(vis[i][j])continue;
        xs.clear();
        ys.clear();
        cont = 0;
        dfs(i,j);
        if(cont!=3){
          flag = false;
          break;
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        if(xs[0]==xs.back() || ys[0]==ys.back() || xs.back()==xs[0]+2 ||ys.back()==ys[0]+2){
          flag = false;
          break;
        }
      }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
}

