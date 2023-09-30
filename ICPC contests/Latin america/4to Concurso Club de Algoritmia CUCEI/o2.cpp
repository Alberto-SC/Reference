#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int bfs(int start, int end, int k, vector<set<int>> &graph, vector<set<int>> &graphMod){
	vector<bool> visited(graph.size(), false);
	priority_queue<pair<int,int>> q;
	q.emplace(0, start);
 
	while(!q.empty()){
		int steps = -q.top().first;
		int me = q.top().second;
		q.pop();
 
		if(me == end){
			return steps;
		}
 
		for(auto child:graph[me]){
			if(!visited[child]){
				q.emplace(-(steps+1), child);
				visited[child] = true;
			}
		}
 
		for(auto child:graphMod[me%k]){
			if(!visited[child]){
				q.emplace(-(steps+2), child);
				visited[child] = true;
			}
		}
 
	}
	
	return -1;
}
 
int main(){__
	int n, m, k; cin >> n >> m >> k;
	vector<set<int>> graph(n+1);
	vector<set<int>> graphMod(k);
	
	int u,v; 
	while(m--){
		cin >> u >> v;
		graph[u].insert(v);
		graphMod[u%k].insert(v);
 
	}
	int s,t; cin >> s >> t;
 
	cout << bfs(s, t, k, graph, graphMod) << endl;
} 