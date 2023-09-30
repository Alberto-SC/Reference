#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

void bfsDist(int start, vector<vector<int>> &graph,vector<vector<int>> &dist){
	vector<bool> visited(graph.size(),false);
	queue<pair<int,int>> q; //node, dist

	q.push({start, 0});
	visited[start] = true;

	while(!q.empty()){
		auto current = q.front();
		q.pop();

		dist[start][current.first] = current.second;

		for(auto child:graph[current.first]){
			if(!visited[child]){
				visited[child] = true;
				q.push({child, current.second+1});
			}
		}
	}
	return;
}

int bfs(int start, int blacks, vector<int> &isBlack, vector<vector<int>> &graph, vector<vector<int>> &dist){
	vector<bool> visited(graph.size(),false);
	queue<pair<int,int>> q; //node, dist
	vector<int> blackList;

	q.push({start, 0});
	visited[start] = true;

	while(!q.empty()){
		auto current = q.front();
		q.pop();

		if(isBlack[current.first]) blackList.push_back(current.first);
		if(blackList.size() == blacks){
			int mx = 0;
			for(int i=0; i<blackList.size()-1; i++){
				for(int j=i+1; j<blackList.size(); j++){
					mx = max(mx, dist[blackList[i]][blackList[j]]);
				}
			}
			return mx;
		}

		for(auto child:graph[current.first]){
			if(!visited[child]){
				visited[child] = true;
				q.push({child, current.second+1});
			}
		}
	}
	return 1000;
}

int main(){
	int n,m; cin >> n >> m;
	vector<int> isBlack(n);
	vector<vector<int>> graph(n);
	for(auto &x:isBlack) cin >> x;
	for(int i=0,u,v; i<n-1; i++){
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<vector<int>> dist(n, vector<int>(n, 0));
	for(int i=0; i<n; i++){
		bfsDist(i, graph, dist);
	}

	int sol = 10000;
	for(int i=0; i<n; i++){
		if(isBlack[i]) sol = min(sol, bfs(i, m, isBlack, graph, dist));
	}

	cout << sol << endl;

	return 0;
}
