#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n,a,b,c;
  cin>>T;
  while(T--){
    cin>>a>>b>>c;
    if(a == b+c || b == a+c || c == a+b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
