#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int a = 0,b = 0;
    a+=s[0]-'0';
    a+=s[1]-'0';
    a+=s[2]-'0';
    b+=s[3]-'0';
    b+=s[4]-'0';
    b+=s[5]-'0';
    if(a==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
