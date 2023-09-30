#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    vector<char> v(26,'$');
    vector<int> g(26,-1); 
    vector<bool> used(26);
    for(int i = 0;i<n;i++){
      if(v[s[i]-'a']!='$')cout<<v[s[i]-'a'];
      else{
        for(int j = 0;j<26;j++){
          if(j == (s[i]-'a') || used[j])continue;
          if(used[s[i]-'a']){
            int u = s[i]-'a';
            int cont = 1;
            while(1){
              cont++;
              if(g[u]== j || g[u]== -1)break;
              u = g[u];
            }
            if(g[u]==j && cont !=26)continue;
          }
          cout<<char(j+'a');
          v[s[i]-'a'] = char(j+'a');
          used[j] = true;
          g[j] = s[i]-'a';
          break;
        }
      }
    }
    cout<<endl;
  }
  return 0;
}
