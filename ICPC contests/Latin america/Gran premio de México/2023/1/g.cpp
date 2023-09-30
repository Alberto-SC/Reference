
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>n;
  // memset(dp,-1,sizeof(dp));
  // if(solve(n,1))cout<<"Jane"<<endl;
  // else cout<<"John"<<endl;
  vector<int> ans(n+1);
  ans[1] = 1;
  int id = 2;
  int c = id;
  int turn = 0;
  int x = 1;
  for(int i =2;i<=n;i++){
    c--;
    ans[i] = turn;
    if(c ==0){
      if(x%2==0)
        id++;
      turn^=1;
      c = id;
      x++;
    }
  }
  // for(int i = 1;i<=n;i++){
  //   cout<<ans[i]<<" ";
  // }
  // cout<<endl;
  if(ans[n])cout<<"Jane"<<endl;
  else cout<<"John"<<endl;
  return 0;
}