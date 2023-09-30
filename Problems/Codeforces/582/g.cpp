#include <bits/stdc++.h>
using namespace std;
long long res;
long long get(int cnt) {
	return cnt * 1ll * (cnt - 1) / 2;
}

struct UnionFind {
  int n; 
  vector<int> padre, tam;
  
  
  UnionFind(int N) : n(N), tam(N, 1), padre(N) {
    while (--N) padre[N] = N;
  }
  int Raiz(int u) {
    if (padre[u] == u) return u;
    return padre[u] = Raiz(padre[u]);
  }
  bool SonConexos(int u, int v) {
    return Raiz(u) == Raiz(v);
  } 
  void Unir(int u, int v) {
    int Ru = Raiz(u); 
	int Rv = Raiz(v);
    if (Ru == Rv) return;
    if (tam[Ru] < tam[Rv]) swap(u, v);
    --n;
    res-=get(tam[Ru]);
    res-=get(tam[Rv]);
    padre[Rv] = Ru;
    tam[Ru] += tam[Rv];
    res+=get(tam[Ru]);
  }
  
  int NumC(){
  	int Nc = 1;
  	int padreA = Raiz(0);
	for(int i=1;i<=100;i++){
    	    if(Raiz(i)!= padreA) {
			Nc++; 
    	    padreA = Raiz(i);	
			}
    }
	}
  int Tamano(int u) {
    return tam[Raiz(u)];
  }
};

int main(){
    int n,m,u,v,w,qi;
	cin >> n >> m;	
	res = 0;
	vector<pair<int, pair<int, int>>> e(n -1);
    for(int i =0;i<n-1;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        e[i]={w,{u,v}};
    }   
    vector<pair<int,int>> q(m);
    vector<long long> ans(m);
    for(int i=0;i<m;i++){
        cin>>qi;
        q[i]={qi,i};
    }
    sort(e.begin(),e.end());
    sort(q.begin(),q.end());
    UnionFind DSU(n);
    int j = 0;
    for(int i=0;i<m;i++){
        while ( j < n - 1 && e[j].first <= q[i].first) {
			int u = e[j].second.first;
			int v = e[j].second.second;
			DSU.Unir(u, v);
			++j;
		}
        ans[q[i].second]=res;
    }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
    
}