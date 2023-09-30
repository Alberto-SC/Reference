#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,k;
  cin>>n>>k;
  vector<vector<int>> M(n,vector<int>(n));
  for(int i = 0;i<n;i++)  
    for(int j = 0;j<n;j++)cin>>M[i][j];

  int ans = 0;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if((i+k)-1>=n || (j+k)-1>=n)continue;
      int a = M[i][j];
      int b = M[i+k-1][j];
      int c = M[i][j+k-1];
      int d = M[i+k-1][j+k-1];

      if(a==b && b==c && c==d)ans++;
    }
  }
  cout<<ans<<endl;
}