#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>n;
  int ans = 1e18;
  for(int i = 1;i<=n;i++){
    int x = (i*(i+1))/2;
    int y = x-i;
    if(x+y>n)break;
    int f = n-(x+y);
    ans = min(ans,i+(i-1)+((f+i-1)/i));
  }
  cout<<ans<<endl;
  return 0;
}