#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 
signed main() {__
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(auto &c:v)cin>>c;
    for(int i = 0;i<n;i++){
      int mn = 1e9;
      int mx = -1e9;
      if(v[i].size()!=s.size())continue;
      for(int j = 0;j<s.size();j++){
        int d = ((v[i][j]-s[j]%26)+26)%26;
        mn = min(mn,d);
        mx = max(mx,d);
      }
      if(mn == mx){
        cout<<v[i]<<endl;
        break;
      }
    }
    return 0;
}

