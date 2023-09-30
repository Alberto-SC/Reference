#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main(){__
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    if(n == 1 && m == 1)cout<<0<<endl;
    else if(n== 1|| m == 1)cout<<1<<endl;
    else cout<<2<<endl;
  }
  return 0;
}
