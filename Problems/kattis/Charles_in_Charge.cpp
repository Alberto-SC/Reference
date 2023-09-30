#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


typedef long long Costo;
const int MAXN = 200020;
const Costo INF = 1e18+1;
int NODOS = 0;
typedef pair<Costo, int> CostoNodo;
vector<CostoNodo> grafoCosto[MAXN];
vector<CostoNodo> grafoCostoC[MAXN];
const bool bi = true;
long long maxdist;
void AgregarArista(int u, int v, Costo c) {
  grafoCosto[v].push_back(CostoNodo(c, u));
  grafoCosto[u].push_back(CostoNodo(c, v));
}
vector<Costo> dist(MAXN);
 void Dijkstra(int s,int rest) {
  for( int i = 0; i < NODOS; i++ ) dist[i] = INF;
  priority_queue<CostoNodo> pq;
  pq.push(CostoNodo(0, s)), dist[s] = 0;
  while (!pq.empty()) {

    Costo p = -pq.top().first;
    int u = pq.top().second; pq.pop();
    if (dist[u] < p) continue;
    for (CostoNodo arista : grafoCosto[u]) {
      int v = arista.second;
      p = dist[u] + arista.first;
      if (p < dist[v]&&arista.first<=rest) dist[v] = p, 
        pq.push(CostoNodo(-p, v));
    }
  }
}
bool impossible(long long maxarrow) {	// Is it impossible to get in time using only edges of size at most maxarrow?
	Dijkstra(0, maxarrow);
	return (dist[NODOS-1]> maxdist);
}
int main(){
	long long n,m,x,u,v,p,maxd = -1000,res = 0;
	cin>>n>>m>>x;
	for(int i = 0;i<m;i++){
		cin>>u>>v>>p;
		if(p>maxd)maxd = p;
		AgregarArista(--u,--v,p);
	}
	NODOS = n;
	Dijkstra(0,maxd);
	maxdist = dist[n-1];
	maxdist = (maxdist*(100+x))/100;
	long long l = 0,r = maxd,mid;
	long long lo = -1;
	long long hi = maxd + 1;
	while (hi - lo > 1) {	// Binary search for solution
		long long mid = (lo+hi)/2;
		(impossible(mid) ? lo : hi) = mid;
	}
	cout << hi <<'\n';

	return 0;
}