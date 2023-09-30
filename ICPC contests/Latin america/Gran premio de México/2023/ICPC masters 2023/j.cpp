#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,k,f;
  cin>>n>>k>>f;
  
  vector<int> F[f];
  for(int i = 0;i<f;i++){
    int x;
    cin>>x;
    for(int j = 0;j<x;j++){
      int d;
      cin>>d;
      d--;
      F[i].push_back(d);
    }
  }

  int ans = 0;
  for(int mask = 1;mask<(1ll<<f);mask++){
    int x = 0;
    for(int i = 0;i<f;i++){
      if(mask&(1ll<<i)){
        for(auto c:F[i]){
          x|=(1ll<<c);
        }
      }
    }
    bitset<55> b(x);
    if(n-b.count()>=k)ans = max(ans,(int)__builtin_popcount(mask));
  }
  cout<<ans<<endl;
  return 0;
}