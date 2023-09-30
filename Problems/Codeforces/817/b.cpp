#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;

    for(int i = 0;i<n;i++){
      if(s[i]=='G' || s[i]=='B')s[i]= 'A';
      if(t[i]=='G' || t[i]=='B')t[i] = 'A';
    }
    if(s==t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
}

