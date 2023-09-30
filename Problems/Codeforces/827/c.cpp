#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    char M[8][8];
    for(int i = 0;i<8;i++){
      for(int j = 0;j<8;j++){
        cin>>M[i][j];
      }
    }
    char ans;
    for(int i = 0;i<8;i++){
      int contR = 0,contB = 0;
      for(int j = 0;j<8;j++){
        contR += M[i][j]=='R';
        contB += M[j][i]=='B';
      }
      if(contR ==8)ans = 'R';
      if(contB ==8)ans = 'B';
    }
    cout<<ans<<endl;
  }
  return 0;
}

