#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Lista;
typedef pair<int, int> Par;
#define print(A)for(auto c:A)cout<<c<<" ";
vector<int> primes;
void criba(int n){
	vector<bool> isPrime(n+1,true);
    for (int i=2; i<=n; ++i){
		if(isPrime[i])
			primes.push_back(i);
		for(int p: primes){
			int d = i*p;
			if(d>n)break;
			isPrime[d] = false;
			if( i % p == 0)break;
		}	
	}  
}
map<long long int,int> fact;
void getFactorization(long long int x) { 
    fact.clear();
	for(long long int p: primes){
		if(p*p >x)break;
		int pot = 0; v
    	while (x % p == 0) { 
			pot++;
			x /= p; 
    	} 
		if(pot) fact[p]+=pot;
	}
	if(x>1)fact[x]++;
} 
struct Bipartito {
    vector<int> M[1000];
    vector<int> F[1000];
	int n; Lista pareja;
	vector<Lista> aristas;
	vector<bool> lado, visitado;
	Bipartito(int N) : lado(N), pareja(N),
			visitado(N), aristas(N), n(N) {}

	void AgregarArista(int u, int v) {
		aristas[u].push_back(v);
		aristas[v].push_back(u);
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
		return pares.size();//Cardinalidad = pares.size()
	}
};

int main(){
    int t,n,val;
    cin>>t;
    criba(100000);
    while(t--){
        cin>>n;
        Bipartito B(n*100);
        vector<int> v(n);
        for(int i = 0;i<n;i++)
            cin>>v[i];
        char c;
        for(int i = 0;i<n;i++){
            cin>>c;
            getFactorization(val);
            if(c == 'M'){
            for(auto it = fact.cbegin(); it != fact.cend(); ++it){
                cout<<it->first<<" ";
                B.M[it->first].push_back(i);
            }
            cout<<endl;
            B.AgregarIzq(i);
            }
            else{
            for(auto it = fact.cbegin(); it != fact.cend(); ++it){
                cout<<it->first<<" ";
                B.F[it->first].push_back(i);
            }
            cout<<endl;
            B.AgregarDer(i);
            }
        } 
        int mx = B.MaxEmparejamiento();
        cout<<mx<<endl;;
    }
}
