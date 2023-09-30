#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 


vector<char> valid(string s,vector<string> S){
  int n = S.size();
  set<string> pref;
  set<string> suf;
  for(int i = 0;i<s.size()-1;i++){
    pref.insert(s.substr(0,i+1));
  }

  for(int i = s.size()-1;i>=1;i--){
    suf.insert(s.substr(i));
  }
  vector<char> ans(n,'F');

  for(int i = 0;i<n;i++){
    if(pref.count(S[i])){
      ans[i] = 'P';
      pref.erase(S[i]);
    }
    else if(suf.count(S[i])){
      ans[i] = 'S';
      suf.erase(S[i]);
    }
    else break;
  }
  return ans;
}

signed main(){__
  int n;
  cin>>n;
  vector<string> S((2*n)-2);
  vector<string> v;
  for(int i = 0;i<(2*n)-2;i++){
    cin>>S[i];
    if(S[i].size()==n-1){
      v.push_back(S[i]);
    }
  }
  vector<char> ans = valid(v[0]+v[1].back(),S);
  if(ans.back()=='F')ans = valid(v[1]+v[0].back(),S);
  for(auto c:ans)cout<<c;
  cout<<endl;

  return 0;
}
