#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    char c;
    cin>>c;
    string s;
    cin>>s;
    s+=s;
    int lastG = n*2;
    int ans = 0;
    for(int i= (n*2)-1;i>=0;i--){
      if(s[i]=='g'){
        lastG = i;
      }
      if(s[i]==c && i<=n-1){
        ans = max(ans,lastG-i);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
