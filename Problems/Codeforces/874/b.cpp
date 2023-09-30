#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
      v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    vector<int> ans(n);
    sort(b.begin(),b.end());
    for(int i= 0;i<n;i++)
      ans[v[i].second] = b[i];
    
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
  }
  return 0;
}