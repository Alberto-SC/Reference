#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    if(n&1){
      cout<<1<<" ";
      for(int i = 2;i<=n;i+=2)
        cout<<i+1<<" "<<i<<" ";
      
    }
    else{
      for(int i = 1;i<=n;i+=2)
        cout<<i+1<<" "<<i<<" ";
      
    }
  
    cout<<endl;
  }
  return 0;
}
