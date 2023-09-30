#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(vector<pair<int,int>> v){
  sort(v.begin(),v.end());

  set<int> s1;
  set<int,greater<int>> s2;

  int n = v.size();
  vector<int> suf(n);
  suf[n-1] = v[n-1].second;

  for(int i = n-2;i>=0;i--)
    suf[i] = max(suf[i+1],v[i].second);
  
  int ans = 1e9+7;

  for(int i = 0;i<n;i++){
    int mx = i+1<n?suf[i+1]:0;

    if(mx>=v[i].first || s1.size()==0)
      ans = min(ans,abs(mx-v[i].first));
    else {
      auto bestG = s1.lower_bound(v[i].first);
      auto bestL = s2.lower_bound(v[i].first);
      if (bestG != s1.end()) {
        ans = min(ans,*bestG-v[i].first);
      }
      if (bestL != s2.end()) {
        ans = min(ans,v[i].first-*bestL);
      }
      ans = min(ans,v[i].first-v[i-1].first);
      ans = min(ans,v[i].first-mx);
    }    

    s1.insert(v[i].second);
    s2.insert(v[i].second);
  }
  return ans;
}

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<pair<int,int>> v(n);
    for(auto &[x,y]:v)cin>>x>>y;

    int ans = solve(v);
    for(int i = 0;i<n;i++)
      swap(v[i].first,v[i].second);
    ans = min(ans,solve(v));

    cout<<ans<<endl;
  }
  return 0;
}