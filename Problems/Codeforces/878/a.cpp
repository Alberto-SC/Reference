#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    string ans = "";
    for(int i = 0;i<n;){
      int j = i+1;
      while(j<n && s[i]!=s[j]){
        j++;
      }
      ans+=s[i];
      i = j;
      i++;
    }
    cout<<ans<<endl;
  }
  return 0;
}