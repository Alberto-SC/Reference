/**
 * Author: Alberto Silva
 * Date: 2020-09-13
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left to right.
 * If there are cycles, the returned list will have size smaller than $n$ -- nodes reachable
 * from cycles will not be returned.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */

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

// Get all topolical sorts
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
int AlltopoSort(vector<int> graph[], int N){	
    stack<int> s;
	int recS[N];
	vector<int> ATP;
	int c = 0;
    if(ALLTPS(s,recS,ATP,c) == 2 )
    	return 1;
    return 0;
}

