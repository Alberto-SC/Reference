#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int n,m,w,u,v;
  while(cin>>n>>m){
    int ans =1;
    bool flag = false;
    for(int i = 0;i<m;i++){
      cin>>w>>u>>v;
      if(w&1){
        ans*=w;
      }
    }
    cout<<ans<<endl;

  }
  return  0;
}

