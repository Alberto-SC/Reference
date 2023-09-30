#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

signed main(){__
  int T = 1,n,a,b;
  cin>>T;
  while(T--){
    cin>>n;
    int mx = 0,ans = 0;
    for(int i = 0;i<n;i++){
      cin>>a>>b;
      ans+=min(a,b)*2;
      mx = max({mx,a,b});
    }
    ans+=mx*2;
    cout<<ans<<endl;
  }
  return 0;
}
