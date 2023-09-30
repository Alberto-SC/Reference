#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
signed main(){__
  int T,n;
  cin>>T;
  map<char,int> mp;
  mp['S'] = 0;
  mp['M'] = 1;
  mp['L'] = 2;
  while(T--){
    string s,t;
    cin>>s>>t;
    if(s.back()==t.back()){
      if(s==t)cout<<"="<<endl;
      else if(s.back()=='S'){
        if(s.size()>t.size()){
          cout<<"<"<<endl;
        } 
        else cout<<">"<<endl;
      }
      else{
        if(s.size()>t.size()){
          cout<<">"<<endl;
        } 
        else cout<<"<"<<endl;

      }
    }
    else{
      bool f = mp[s.back()]<mp[t.back()];
      if(f)cout<<"<"<<endl;
      else cout<<">"<<endl;
    }
  }
  return 0;
}
