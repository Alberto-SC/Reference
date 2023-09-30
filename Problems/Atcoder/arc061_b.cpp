#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
  int h,w,n,x,y;
  map<pair<int,int>,set<pair<int,int>>> mp;
  cin>>h>>w;
  cin>>n;
  vector<int> fx = {-1,-1,-1,+1,+1,+1,-0,+0,-0};
  vector<int> fy = {+1,-0,-1,+1,-0,-1,+1,+0,-1};

  for(int i = 0;i<n;i++){
    cin>>x>>y;
    for(int j= 0;j<9;j++){
      int nx = x+fx[j];
      int ny = y+fy[j];
      if(nx<=1 || ny<=1)continue;
      if(nx>= h || ny>=w)continue;
      mp[{nx,ny}].insert({x,y});
    }
  }
  vector<int> ans(10);
  int total = (h-2)*(w-2);
  ans[0] = total;
  for(auto c:mp){
    ans[c.second.size()]++;
    ans[0]--;
  }
  for(auto c:ans)cout<<c<<endl;
  cout<<endl;
  return 0;
}
