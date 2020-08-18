vi topoSort(){
	vi ans;
	queue<int> q;
	forn(i,n){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.pb(u);
		for(auto v:adj[u]){
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	assert(ans.size() == n);
	return ans;
}
 