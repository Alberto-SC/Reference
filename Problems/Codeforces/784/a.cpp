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
    if(n<=1399)cout<<"Division 4"<<endl;
    else if(n<=1599)cout<<"Division 3"<<endl;
    else if(n<=1899)cout<<"Division 2"<<endl;
    else cout<<"Division 1"<<endl;
  }
  return 0;
}
