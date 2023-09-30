#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef long long Costo;
typedef pair<Costo,int> costos;
typedef vector<costos> grafop;
	vector<Par> pares;
struct Bipartito {
	int n; Lista pareja;
	vector<grafop> aristas;
	vector<bool> lado, visitado;
	Bipartito(int N) : lado(N), pareja(N),
			visitado(N), aristas(N), n(N) {}

	void AgregarArista(int u, int v,Costo c) {
		aristas[u].push_back(make_pair(c,v));
		aristas[v].push_back(make_pair(c,u));
	}
	void AgregarIzq(int u) { lado[u] = true;}
	void AgregarDer(int u) { lado[u] = false;}
	int CaminoIncremental(int u,int max) {
		visitado[u] = true; 
		for (int i = 0; i < aristas[u].size(); ++i)
			if (pareja[aristas[u][i].second] == -1 && aristas[u][i].first <= max)
				return pareja[aristas[u][i].second] = u;
		for(int i = 0; i < aristas[u].size(); ++i){
			if(aristas[u][i].first > max)continue;
			int v = aristas[u][i].second;
			if (visitado[pareja[v]]) continue;
			if (CaminoIncremental(pareja[v],max) != -1)
				return pareja[v] = u;
		}
		return -1;
	}

	int  MaxEmparejamiento(int max) {
		fill(visitado.begin(),visitado.end(), false);
		fill(pareja.begin(), pareja.end(), -1);
		for (int i = 0; i < n; ++i) {
			if (!lado[i]) continue;
			CaminoIncremental(i,max);
			fill(visitado.begin(),
				 visitado.end(), false);
		}
		for(int i = 0;i<n;i++){
		}
		for (int i = 0; i < n; ++i){	
			if (!lado[i] && pareja[i] != -1){
				pares.push_back(Par(pareja[i], i));
			}
		}
		/*for(int i = 0;i<n;i++)
			cout<<pares[i].first<<"," <<pares[i].second<<endl;
			*/return pares.size();
	}
};


int main(){
	long long  n,x,y;
	cin>>n;
	Costo maxc =-1000;
	struct Bipartito b(2*n);
	//b = Bipartito(2*n);
	vector<Par> s;
	vector<Par> t;
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		s.push_back(make_pair(x,y));
	}
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		t.push_back(make_pair(x,y));
	}

	for(int i = 0; i<n; i++){
		b.AgregarIzq(i);
		for(int j = 0; j<n; j++){
			Costo c =fabs(s[i].first-t[j].first)+fabs(s[i].second-t[j].second);
			//cout<<"COSTO:  "<<c<<endl;
			if(c>maxc) maxc= c;
			b.AgregarArista(i,n+j,c);
		}
	}
	for(int i = n;i<2*n;i++){b.AgregarDer(i);}
	long long l = 0,r = maxc,mid,res ;
	//cout<<b.MaxEmparejamiento(6)<<endl;
	while(l<= r){
		mid = (l+r)/2;
		pares.clear();
		int match = b.MaxEmparejamiento(mid);
		//cout<<mid<<endl;
		if(match  == n){
			res = mid;	
			r = mid-1;
		}
		else{
			l = mid +1;
		} 

	}
	cout<<res;
}