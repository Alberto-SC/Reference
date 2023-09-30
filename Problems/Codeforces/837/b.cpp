#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,m,u,v;
  cin>>T;
  while(T--){
    cin>>n>>m;
    vector<int> mn(n,1e9);
    for(int i = 0;i<m;i++){
      cin>>u>>v;
      u--,v--;
      if(u>v)swap(u,v);
      mn[u] = min(mn[u],v);
    }
    for(int i = n-2;i>=0;i--){
      mn[i] = min(mn[i],mn[i+1]);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
      if(mn[i]==1e9) ans += n-i;
      else ans+=mn[i]-i;
    }

    cout<<ans<<endl;
  }
  return 0;
}

