#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    if(k>34)cout<<n+1<<endl;
    else cout<<min(n+1,1ll<<k)<<endl;
  }
  return 0;
}