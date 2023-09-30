#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
signed main(){__
  string s,t;
  cin>>s>>t;
  int x = stoll(t);
  int y = x/2;
  if(x&1){
    cout<<s<<""<<y<<"5"<<endl;
  }
  else{
    cout<<s<<""<<x<<endl;
  }
  return 0;
}
