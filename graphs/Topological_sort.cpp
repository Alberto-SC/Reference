#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
set<int> graphL[maxn];
vector<int> inDegree(maxn,0);
void add_edge(int u,int v){
	inDegree[v]++;
	graph[u].push_back(v);
}
int n;
vector<int> topoSort(){
	vector<int> ans;
	priority_queue<int,vector<int>,greater<int>> q; // priority queue if you need a small lexicografic order
	// queue<int> q;
	for(int i = 0;i<n;i++)
		if(inDegree[i] == 0)
			q.push(i);	
	
	while(!q.empty()){
		int u = q.top();
		// int u = q.front(); For a normal queue
		q.pop();
		ans.push_back(u);
		for(auto v:graph[u]){
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	return ans;
}

int main(){
	int m,u,v;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		cin>>u>>v;
		u--,v--;
		add_edge(u,v);
	}
	for(int i=0;i<n;i++)
        sort(graph[i].begin(),graph[i].end());
    
	vector<int> tsort = topoSort();
	for(auto c:tsort)cout<<c+1<<" ";
	cout<<endl;
	return 0;
}
// [TESTED in timus 1439]