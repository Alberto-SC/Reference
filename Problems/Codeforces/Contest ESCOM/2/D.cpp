#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define print(A)for(auto c:A)cout<<c.first<<" "<<c.second<<"\n";
#define printT(A)for(auto c:A)cout<<get<0>(c)<<" "<<get<1>(c)<<" "<<get<2>(c)<<"\n";
vector<int> h;
vector<int> padre;
struct edge{
    int u,v,r,c,i;
    edge() : u(), v(), r(),c(),i(){}
    edge(int U,int V, int R,int C,int I): u(U),v(V),r(R),c(C),i(I){}

};
bool comp(edge U, edge V){
    if(U.r == V.r) return U.c < V.c;
    return U.r < V.r;
}
int raiz(int i) {
		while(i != padre[i]) i = padre[i];
		return i;
	}
bool conexos(int u,int v){
    return raiz(u) == raiz(v);
}

void union_find(int u,int v){
    if(conexos(u,v))return;
    u = raiz(u);
    v = raiz(v);
    if(h[u] < h[v])padre[u] = v; 
    else{
        padre[v] = u;
        if(h[u]  == h[v])++h[u];
    }    
}
long long kruskal(vector<edge> &edges){
	long long cost = 0;
	edge ed;
	sort(edges.begin(),edges.end(),comp);
	int n = edges.size();
    for (int i = n-1; i >=0; i--) {
		ed = edges[i];
		if (!conexos(ed.u, ed.v)) { 
			cost += ed.c;
			union_find(ed.u, ed.v);
		}
	}
	return cost;
}
int main(){
	ios_base::sync_with_stdio(0);
	std::ios::sync_with_stdio(0);
    ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
    // ofstream cout("output.txt");
	int n,a,b,r,p;
	cin>>n;
    vector<edge> edges;
    map<int,int> mapeo;
    int cont = 0;
	for(int i = 0;i<n;i++){
		cin>>a>>b>>r>>p;
        if(mapeo.find(a) == mapeo.end())mapeo[a] = cont++;
        if(mapeo.find(b) == mapeo.end())mapeo[b] = cont++;
        edges.push_back(edge(mapeo[a],mapeo[b],r,p,i+1));
	}
    padre.resize(cont);
    h.resize(cont,1);
    while(cont--)padre[cont] = cont;
    cout<<kruskal(edges)<<endl;
    for(int i =0;i<n;i++)
         cout<<edges[i].i<<" ";
    cout<<endl;
	return 0;
}
