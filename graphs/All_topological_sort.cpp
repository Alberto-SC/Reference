#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Arista;
const int MAXN = 10000; 
int NODOS = 0;  
vector<int> grafo[MAXN]; 
vector<int> indegree; 
vector<int> vis;

void AgregarArista(int u, int v){
	grafo[u].push_back(v); 
	indegree[v]++;
}



int ALLTPS(stack<int>& s,int *recStack,vector<int>& res,int& c){
    int flag = 0;
	for(int i = 0;i<NODOS; i++){
		if(vis[i] == -1&& indegree[i] == 0){
			for(int u:grafo[i]){
					indegree[u]--;
			}
		
		vis[i] = 1;
		recStack[i] = 1;
		res.push_back(i);
		if(ALLTPS(s,recStack,res,c)==1)
			return 1;
		if(c ==1)
			return 2;
			
		vis[i] = 0;
		res.erase(res.end()-1);
			for(int u:grafo[i]){
					indegree[u]++;
			}
		flag =1 ;
		}
	}
	if(flag == 0){
		if(res.size() <NODOS)
			return 1;
		for (int i = 0; i < res.size(); i++)
		cout << res[i]+1 << " ";
		c++;
	}   
    return 0;
}
int  AlltopoSort(vector<int> graph[], int N){	
    stack<int> s;
	int recS[N];
	vector<int> ATP;
	int c = 0;
    if(ALLTPS(s,recS,ATP,c) == 2 )
    	return 1;
    return 0;
}

int main(){
	int N, M, x, y,l,T;
	cin>>N>>M;
    NODOS = N;
    indegree.resize(N);
    vis.resize(N,-1);
    for(int i = 0; i < M; i++){
    	cin >> x >> y;
    	AgregarArista(--x, --y);
    }
    if(AlltopoSort(grafo,N)==0)
    	printf("Sandro fails.");
	return 0;
}
