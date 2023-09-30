#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

vector<int> best(1e7+3,1e18);
vector<int> G(1e7+3,0);
signed main(){__
  int n;
  cin>>n;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  for(int  i = 0;i<n;i++)
    G[nums[i]] = i+1;
  map<int,vector<int>> mp;
  for(int i = 0;i<n;i++){
    mp[nums[i]].push_back(i+1);
  }
  int a,b;
  int mn = 1e18;
  for(auto c:mp){
    if(c.second.size()>=2){
      mn = c.first;
      a = c.second[0];
      b = c.second[1];
      break;
    }
  }
  for(int i = 1;i<=1e7;i++){
    vector<pair<int,int>> v;
    for(int x = i;x<=1e7;x+=i){
      if(G[x])v.push_back({x,G[x]});
      if(v.size()==2)break;
    }
    if(v.size()==2){
      best[i] = (v[0].first*v[1].first)/i; 
      if(best[i]<mn){
        mn = best[i];
        a = v[0].second;
        b = v[1].second;
      }
      mn = min(mn,best[i]);
    }
  }
  if(b<a)swap(a,b);
  cout<<a<<" "<<b<<endl;
  return 0;
}
