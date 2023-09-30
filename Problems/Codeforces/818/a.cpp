#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,k;
  cin>>T;
  while(T--){
    cin>>n; 
    int x = ((n/3)*3*2)-1;
    int y = (((n/2)-(n/3))*4)-1;
    int z = (n-(n/2));
    y  = max(y,0ll);
    x = max(x,0ll);
    cout<<x<<" "<<y<<" "<<z<<endl;
    cout<<x+y+z<<endl;
  }
  return 0;
}

