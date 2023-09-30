#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>n;
  string s;
  cin>>s;
  int ans = 0;
  for(int i = 0;i<s.size();i++){
    if(s[i]!='0' && s[i]!='6' && s[i]!='8')ans++;
  }
  cout<<ans<<endl;
}