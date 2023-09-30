#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long
signed main(){__
  int h,w,x;
  cin>>h>>w;
  vector<pair<int,int>> edges;
  for(int i = 0;i<h;i++){
    cin>>x;
    edges.push_back({x,1});
  }
  for(int i = 0;i<w;i++){
    cin>>x;
    edges.push_back({x,2});
  }
  sort(edges.begin(),edges.end());
  
  int c = 0,r = 0;
  int ans = 0;
  for(auto e:edges){
    if(e.second ==1){
      ans+=e.first*((w+1)-c);
      r++;
    }
    else {
      ans+=e.first*((h+1)-r);
      c++;
    }
  }
  cout<<ans<<endl;
}


