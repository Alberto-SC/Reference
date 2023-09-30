#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    n = s.size();
    int last = '0';
    s.push_back('1');
    for(int i = 0;i<n;){
      int j = i;
      while(j<n && s[j]=='?')j++;

      if(s[j]==last)
        for(int k = i;k<j;k++)s[k] = last;
      else for(int k = i;k<j;k++)s[k] = '0';

      last = s[j];
      if(j == i)j++;
      i = j;
    }    
    s.pop_back();
    cout<<s<<endl;
  }
  return 0;
}