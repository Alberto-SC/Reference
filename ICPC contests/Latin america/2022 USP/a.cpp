#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n,l,r;
  cin>>n;
  vector<pair<int,int>> p;
  for(int i = 0;i<n;i++){
    cin>>l>>r;
    p.push_back({l,r});
  }
  sort(p.begin(),p.end());
  int L = -1e18, R = 1e18;
  vector<int> ans;
  for(int i = 0;i<n;i++){
    int LL = L, RR  = R;
    L = max(L,p[i].first);
    R = min(R,p[i].second);
    cout<<L<<" "<<R<<endl;
    if(R<L){
      ans.push_back(LL);
      L = p[i].first  ;
      R = p[i].second;
    }
  }
  ans.push_back(L);
  cout<<ans.size()<<endl;
  for(auto c:ans)cout<<c<<" ";
  cout<<endl;
 
}


