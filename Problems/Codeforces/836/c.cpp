#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,x;
  cin>>T;
  while(T--){
    cin>>n>>x;
    if(n%x)cout<<-1<<endl;
    else{
      vector<int> ans(n);
      for(int i = 0 ;i<n;i++){
        if(i ==0)ans[i] = x;
        else if(i == n-1)ans[i] = 1;
        else ans[i] = i+1;
      }
      int px =x;
      while(px<n){
        px*=x;
      }
      int y = n/x;
      int last = n;
      while(y>=x && y%x==0){
        ans[y-1] = last;
        last = y;
        if(y%x)break;
        y/=x;
      }
      
      if(y!=1)
        ans[x-1] = last;
 
      for(auto c:ans)cout<<c<<" ";
      cout<<endl;
    }
  }
  return 0;
}
