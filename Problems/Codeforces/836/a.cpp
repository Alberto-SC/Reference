#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T;
  cin>>T;
  while(T--){
    string s,t;
    cin>>s;
    t = s;
    reverse(t.begin(),t.end());
    cout<<s<<t<<endl;
  }
  return 0;
}
