#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x first
#define y second
struct rect{
  int x0,y0,x1,y1;
};
typedef double ld;

const int maxn = 107;
vector<ld> D(maxn);

vector<pair<int,ld>> graph[maxn];
ld INF = 1e12;
void dijkstra(int s,int n) {
    for(int i = 0;i<n;i++){
      D[i] = INF;
    }
    vector<bool> u(n, false);
    D[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || D[j] < D[v]))
                v = j;
        }

        if (D[v] == INF)
            break;

        u[v] = true;
        for (auto edge : graph[v]) {
            int to = edge.first;
            ld len = edge.second;

            if (isless(D[v] + len , D[to])) {
                D[to] = D[v] + len;
            }
        }
    }
}


ld distance(rect a, rect b){
  ld d = 0;
  if((a.x0>=b.x0 && a.x0<=b.x1) || (a.x1>= b.x0 && a.x1<=b.x1)){
    if(a.y1>=b.y0){
      return a.y1-b.y0;
    }
    else if(b.y1>=a.y0){
      return b.y1-a.y0;
    }
  }

  if((a.y0 >=b.y1 && a.y0<= b.y0)|| (a.y1 >= b.y1 && a.y1<=b.y0)){
    if(a.x0>= b.x1){
      return a.x0-b.x1;
    }
    else if(b.x1>=a.x0) 
      return b.x0-a.x1;
  }

  
  if(a.y1<=b.y0){
    swap(a,b);
  }
  if(a.x0==0){
    int Ax = a.x1-b.x0;
    int Ay = a.y1-b.y0;
    d = sqrt((Ax*Ax)+(Ay*Ay));
  }
  else{
    ld Ax = a.x0-b.x1;
    ld Ay = a.y1-b.y0;
    d = sqrt((Ax*Ax)+(Ay*Ay));
  }
  
  return d;
}

signed main(){__
  int T,n,W,H,w,h,d,k;
  freopen("street.in", "r", stdin);
  cin>>T;
  while(T--){
    cin>>n>>H>>W;
    for(int i = 0;i<n+2;i++)graph[i].clear();
    vector<rect> R;
    for(int i = 0;i<n;i++){
      cin>>h>>w>>d>>k;
      rect r= {k?W-w:0,min(d+h,H),k?W:w,d};
      R.push_back(r);
    }

    rect r = {0,0,W,0};
    R.push_back(r);
    r = {0,H,W,H};
    R.push_back(r);
    for(int i = 0;i<n+2;i++){
      for(int j = 0;j<i;j++){
        ld x = distance(R[i],R[j]);
        graph[i].push_back({j,x});
        graph[j].push_back({i,x});
      }
    }

    dijkstra(n,n+2);
    cout<<fixed<<setprecision(6);
    cout<<D[n+1]<<endl;
  }

}

