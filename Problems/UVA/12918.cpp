#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

signed main(){__
  int T,n,m;
  cin>>T;
  while(T--){
    cin>>n>>m;
    int x = m-1;
    x = (x*(x+1))/2;
    int y = (m-n)-1;
    y = (y*(y+1))/2;
    cout<<x-y<<endl;
  }
  
}
