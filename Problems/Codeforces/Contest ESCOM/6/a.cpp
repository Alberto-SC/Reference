#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Lista;
typedef pair<int, int> Par;
struct Bipartito {
	int n; Lista pareja;
	vector<Lista> aristas;
	vector<bool> lado, visitado;
	Bipartito(int N) : lado(N), pareja(N),
			visitado(N), aristas(N), n(N) {}

	void AgregarArista(int u, int v){
		aristas[u].push_back(v);
    }

	void AgregarIzq(int u) { lado[u] = true; }
	void AgregarDer(int u) { lado[u] = false; }

	int CaminoIncremental(int u) {
		visitado[u] = true;
		for (int i = 0; i < aristas[u].size(); ++i)
			if (pareja[aristas[u][i]] == -1)
				return pareja[aristas[u][i]] = u;
		for(int i = 0; i < aristas[u].size(); ++i){
			int v = aristas[u][i];
			if (visitado[pareja[v]]) continue;
			if (CaminoIncremental(pareja[v]) != -1)
				return pareja[v] = u;
		}
		return -1;
	}

	int MaxEmparejamiento() {
		fill(pareja.begin(), pareja.end(), -1);
		for (int i = 0; i < n; ++i) {
			if (!lado[i]) continue;
			CaminoIncremental(i);
			fill(visitado.begin(),
				 visitado.end(), false);
		}
		vector<Par> pares;
		for (int i = 0; i < n; ++i)
			if (!lado[i] && pareja[i] != -1)
				pares.push_back(Par(pareja[i], i));
		return pares.size();
	}
};

int main(){
    int n,m,count = 0;
    cin>>n>>m;
    string s;
    Bipartito b(100000);
    string mat[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>mat[i][j];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j][0] == 'R')b.AgregarDer((i*m)+j);
            else b.AgregarIzq((i*m)+j);
            if(j+1<= m-1 && (mat[i][j+1][0] != mat[i][j][0]))b.AgregarArista((i*m)+j,(i*m)+j+1);
            if(j-1>= 0 && (mat[i][j-1][0] != mat[i][j][0]))b.AgregarArista((i*m)+j,(i*m)+j-1);
            if(i > 0 && (mat[i-1][j][0] != mat[i][j][0]))b.AgregarArista((i*m)+j,((i*m)+j)-m);
            if(i<n-1 && (mat[i+1][j][0] != mat[i][j][0]))b.AgregarArista((i*m)+j,((i*m)+j)+m);
            if(mat[i][j][1]== '^')count+=0;
            else if(mat[i][j][1]== '>')count+=1;
            else if(mat[i][j][1]== 'v')count+=2;
            else if(mat[i][j][1]== '<')count+=3;
        }
    }    
    int maxE = b.MaxEmparejamiento();
    if((m*n)%2 == 0){
        if(maxE == ((m*n)/2)){
            if(count%4 == 0)cout<<maxE;
            else cout<<maxE-1;
        }
        else
            cout<<maxE<<endl;
    }
    else cout<<maxE<<endl;
    return 0;
}