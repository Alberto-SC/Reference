#include <iostream>
#include <vector>
using namespace std;
vector<int> grafo[10];
vector<int> indegree(10);
vector<int> vis(10,-1);


void Topological_sort(int N, vector<int>& Topo_sort){
	bool flag = false;
	for(int i = 0;i<N;i++){
		if(vis[i]== -1&& indegree[i] == 0){
			for(auto a:grafo[i]) indegree[a]--;
			
			vis[i] = 1;
			Topo_sort.push_back(i);
			Topological_sort(N,Topo_sort);
			

			vis[i] = -1;
			Topo_sort.erase(Topo_sort.end()-1);
			for(auto a:grafo[i]) indegree[a]++;
		
			flag = true;
		}

	}

	if(!flag){
		for(int i = 0;i<Topo_sort.size();i++)
			cout<<Topo_sort[i]<<" ";
	cout<<endl;	
	}

}

int main(){
	int T,N,R,Ri;
	vector<int> v;
	cin>> T;
	for(int i = 0;i<T;i++){
		cin>>N;
		for(int i =0 ;i<N;i++){
			grafo[i].clear();
		}
		for(int j = 0;j<N;j++){
			indegree[j] = 0;
			vis[j] = -1;
			cin>>R;
			for(int k = 0; k<R ; k++){
				cin>>Ri;
				grafo[Ri].push_back(j);
				indegree[j]++;
			}
		}
		v.clear();
		Topological_sort(N,v);
	}
}