#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
signed main(){__
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    string s;
    int M[26][26];
    vector<string> S;
    for(int i = 0;i<26;i++)for(int j = 0;j<26;j++)M[i][j] = 0;
    for(int i = 0;i<n;i++){
      cin>>s;
      S.push_back(s);
      M[s[0]-'a'][s[1]-'a']++;
    }
    int ans = 0;
    for(int i= 0;i<n;i++){
      for(int j = 0;j<26;j++){
        ans+=M[S[i][0]-'a'][j];
      }
      ans-=2*M[S[i][0]-'a'][S[i][1]-'a'];
      for(int j = 0;j<26;j++){
        ans+=M[j][S[i][1]-'a'];
      }
    }
    cout<<ans/2<<endl;
  }
  return 0;
}
