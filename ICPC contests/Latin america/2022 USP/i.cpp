#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,a,b;
  cin>>t;
  while(t--){
    cin>>a>>b;
    int ans = b;
    for(int i = 0;i<9;i++){
      ans*=10;
    }
    ans+=a-(ans%a);
    cout<<ans<<endl;
  }
  
}


