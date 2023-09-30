#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int N,timeD ;
vector<vector<int> > gr(1007);
vector<int> val, comp, z; 
vector<int> values; // 0 = false, 1 = true
void addCondition(int u, int v,int Nu,int Nv) {
  (u*=2)^=Nu;
  (v*=2)^=Nv;
  gr[u^1].push_back(v);
  gr[v^1].push_back(u);
}

// 0 -> 00
// 1 -> 01 
// 2 -> 10
// 3 -> 11 
// For must be same mask = 9 -> 1001
// for must be diferent mask = 6 -> 0110 ./
void canBe(int u,int v,int mask){
  if(!(mask&1)){  
    addCondition(u,v,1,1);
  }
  if(!((mask>>1)&1)){
    addCondition(u,v,1,0);
  }
  if(!((mask>>2)&1)){
    addCondition(u,v,0,1);
  }
  if(!((mask>>3)&1)){
    addCondition(u,v,0,0);
  }
}


int dfs(int i) {
  int low = val[i] = ++timeD, x; z.push_back(i);
  for(int j = 0;j<gr[i].size();j++){
    int e = gr[i][j];
    if (!comp[e])
      low = min(low, val[e] ?: dfs(e));
  } 
  ++timeD;
  if (low == val[i]) do {
    x = z.back(); z.pop_back();
    comp[x] = timeD;
    if (values[x>>1] == -1)
      values[x>>1] = !(x&1);
  } while (x != i);

  return val[i] = low;
}

bool solve() {
  values.assign(N, -1);
  val.assign(2*N, 0); comp = val;
  timeD = 0;
  for(int i = 0;i<2*N;i++) 
          if(!comp[i]) 
              dfs(i);
  for(int i = 0;i<N;i++) if (comp[2*i] == comp[2*i+1]) return 0;
  return 1;
}



vector<pair<int,int> > P;
vector<pair<int,int> > same;
vector<pair<int,int> > diferent;
pair<int,int> S,E;

int getDist(pair<int,int> u,pair<int,int> v,int a,int b){
  int dist = 0;
  if(a ==0){
    dist+=abs(u.first-S.first);
    dist+=abs(u.second-S.second);
  }else{
    dist+=abs(u.first-E.first);
    dist+=abs(u.second-E.second);
  }
  if(b == 0){
    dist+=abs(v.first-S.first);
    dist+=abs(v.second-S.second);
  }
  else{
    dist+=abs(v.first-E.first);
    dist+=abs(v.second-E.second);
  }

  if(a!=b){
    dist+=abs(S.first-E.first);
    dist+=abs(S.second-E.second);
  }
  return dist;
}
int dist[501][501][4];

void allDist(){
  int n = P.size();
  for(int i= 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      int d1 = getDist(P[i],P[j],0,0);
      int d2 = getDist(P[i],P[j],0,1);
      int d3 = getDist(P[i],P[j],1,0);
      int d4 = getDist(P[i],P[j],1,1);     
      dist[i][j][0] = d1;
      dist[i][j][1] = d2;
      dist[i][j][2] = d3;
      dist[i][j][3] = d4;
    }
  }

}

bool check(int upper){
  int n = P.size();
  N = n;
  for(int i = 0;i<2*n;i++){
    gr[i].clear();
  }

  for(int i= 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      int d1 = dist[i][j][0];
      int d2 = dist[i][j][1];
      int d3 = dist[i][j][2];
      int d4 = dist[i][j][3];
      
      int mask = 0;
      if(d1<=upper)mask |= 1<<0;
      if(d2<=upper)mask |= 1<<1;
      if(d3<=upper)mask |= 1<<2;
      if(d4<=upper)mask |= 1<<3;
      canBe(i,j,mask);
    }
  }
  for(int i = 0;i<same.size();i++)
    canBe(same[i].first,same[i].second,9);
  
  for(int i = 0;i<diferent.size();i++)
    canBe(diferent[i].first,diferent[i].second,6);

  return solve();
}

signed main(){__
  int n,a,b,x,y;
  cin>>n>>a>>b;
  cin>>S.first>>S.second>>E.first>>E.second;
  for(int i = 0;i<n;i++){
    cin>>x>>y;
    P.push_back(make_pair(x,y));
  }
  for(int i = 0;i<a;i++){
    cin>>x>>y;
    x--,y--;
    diferent.push_back(make_pair(x,y));
  }
  for(int i = 0;i<b;i++){
    cin>>x>>y;
    x--,y--;
    same.push_back(make_pair(x,y));
  }
  allDist();
  int l = -1,r = 9e6;
  while(l+1<r){
    int m = (l+r)>>1;
    if(check(m))
      r = m;
    else 
      l = m;
  }
  if(r==9e6) r= -1;
  cout<<r<<endl;
  return 0;
}
