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
    if(n%2==0){
      cout<<"NO"<<endl;
      continue;
    }
    vector<pair<int,int>> ans(n);
    for(int i = 1,id = 0;i<=n;i+=2,id++){
      ans[id].first = i;
    }

    for(int i = 2,id = (n/2)+1;i<=n;i+=2,id++){
      ans[id].first = i;
    }

    for(int i= n+(n/2)+1,id = 0;i>n;i--,id++){
      ans[id].second = i;
    }

    for(int i = 2*n,id = (n/2)+1;id<n;id++,i--){
      ans[id].second = i;
    }

    cout<<"YES"<<endl;
    for(auto c:ans){
      cout<<c.first<<" "<<c.second<<endl;
    }
  }
  return 0;
}
