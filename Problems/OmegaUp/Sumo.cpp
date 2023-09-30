#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> aristas;
vector<int> grafo[100000];
void AgregarArista(int u, int v){
	grafo[v].push_back(u);
	grafo[u].push_back(v);
}

bool EsBipartito(int n) {
	vector<char> color(n, -1);
  for (int u = 0; u < n; ++u) {
    if (color[u] >= 0) continue;
    color[u] = 0;
    queue<int> q; q.push(u);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : grafo[u]) {
        if (color[v] < 0) q.push(v), 
             color[v] = 1 - color[u];
        if (color[u] == color[v])
          return false;
      }
    }
  }
  return true;
}
int main (){
	int n,nf,f1,f2,mid,res;
	cin>>n>>nf;
	for(int i = 0; i<nf;i++){
		cin>>f1>>f2;
		aristas.push_back(make_pair(f1,f2));
	}
	int l = 1,r = nf;
	while(l<=r){
		mid = ((l+r)/2);
		for(int i = 0;i<n;i++){
			grafo[i].clear();
		}
		for(int i = 0;i<mid;i++){
			AgregarArista(aristas[i].first-1,aristas[i].second-1);
		}
		//cout<<endl<<mid<<endl;
		for(int i = 0;i<n;i++){
			for(int u: grafo[i]){
				//cout<<i+1<<" "<<u+1	<<endl;
			}
		}
		//cout<<endl;
		if(EsBipartito(n)){	
			//cout<<"Bipartito en: "<<mid<<endl;
			res = mid;
			l = mid+1;
		} 
		else 
			r = mid-1;
	}
	cout<<res+1;
	return 0;
}
