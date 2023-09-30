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
    vector<int> ans(n,n);
    while((ans.back()+1)-(ans[0]-1)<=n){
      ans[0]--;
      ans.back()++;
    }
    if(ans.back()-ans[0]!=n)
      ans[n-2]--,ans[n-1]++;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
  }
  return 0;
}
