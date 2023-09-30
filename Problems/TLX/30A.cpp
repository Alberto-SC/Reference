#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int n,x,y;
  cin>>n>>x>>y;

  if(y<=x){
    int c = n/y;
    int ans =  c*x;
    n-= c*y;
    ans+=n;
    cout<<ans<<endl;
  }
  else{
    cout<<n<<endl;
  }

}
