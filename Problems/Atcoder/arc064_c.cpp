#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
using namespace std;

struct circle{
  int x,y,r;
};

const int maxn = 1007;
const int inf = 1e18;
vector<pair<int,double>> graph[maxn];

double distance(circle a,circle b){
  double x = (a.x-b.x)*(a.x-b.x);
  double y = (a.y-b.y)*(a.y-b.y);
  double dis  = sqrt(x+y);
  return max(0.0,dis-a.r-b.r);
}

signed main(){
  int n,x,y,r;
  vector<circle> circles;
  cin>>x>>y;
  circles.push_back({x,y,0});
  cin>>x>>y;
  circles.push_back({x,y,0});
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>x>>y>>r;
    circles.push_back({x,y,r});
  }
  for(int i = 0;i<n+2;i++){
    for(int j = 0;j<n+2;j++){
      double d = distance(circles[i],circles[j]);
      graph[i].push_back({j,d});
      graph[j].push_back({i,d});
    }
  }  

  set<pair<double,int>> st; 
  vector<double> dist(n+2,inf);
  
  dist[0] = 0;
  st.insert({0,0});
  while(st.size()){
    int u = st.begin()->second;
    st.erase(st.begin());
    for(auto x:graph[u]){
      int v = x.first;
      double w = x.second;
      if(dist[v]> dist[u]+w){
        st.erase({dist[v],v});
        dist[v] = dist[u]+w;
        st.insert({dist[v],v});
      }
    }
  }
  cout<<fixed<<setprecision(10);
  cout<<dist[1]<<endl;
  return 0;
}
