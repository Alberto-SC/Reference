#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){
  int T,n,k,r,c;
  cin>>T;
  while(T--){
    cin>>n>>k>>r>>c;
    r--,c--;
    vector<pair<int,int>> pos;
    int nr =r%k ,nc = c%k;
    int offr = r/k,offc = c/k;

    vector<int> col(k);
    col[nc] = 1;
    vector<vector<char>> ans(k,vector<char>(k,'.'));
    ans[nr][nc] = 'X';

    for(int i = 0;i<k;i++){
      if(i == nr)continue;
      for(int j = 0;j<k;j++){
        if(!col[j]){
          ans[i][j] = 'X';
          col[j] = 1;
          break;
        }
      }
    }
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cout<<ans[i%k][j%k];
      }
      cout<<endl;
    }
  }
  return 0;
}

