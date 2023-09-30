#include <bits/Stdc++.h>
using namespace std;
const int N = 100100;
const int K = 60;
vector<int> graph[N];
int ans = N;
int n;
int dist[N]; 
int b[K];
int q[N]; 
// void solve(int v) {
// 	int topQ = 0;
// 	for (int i = 0; i < n; i++)
// 		dist[i] = N;
// 	dist[v] = 0;
// 	q[topQ++] = v;
// 	for (int i = 0; i < topQ; i++) {
// 		v = q[i];
// 		for (int u : graph[v]) {
// 			if (dist[u] == N) {
// 				dist[u] = dist[v] + 1;
// 				q[topQ++] = u;
// 			} else if (dist[u] >= dist[v]) {
// 				ans = min(ans, dist[v] + dist[u] + 1);
// 			}
// 		}
// 	}
// }
void addedge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void bfs(int root){
    queue<int> q;
    // int best_u,best_v;
    // vector<int> parent(100, -1); 
    vector<int> level(n,-1);
    // vector<bool> vis(100,-1);
    q.push(root);
    level[root] = 0;
    // int min_cycle = INT_MAX;
    while(!q.empty()){
        int u = q.front(); 
        q.pop(); 
        // vis[u] = true;
        // if(level[u]>prune_level)
        //     break;
        for(auto v:graph[u]){
            // if(parent[u] == v)continue;
            if(level[v] == -1){
                level[v] = level[u] +1;
                // parent[v] = u;
                q.push(v);
            }
            else if(level[v]>=level[u]){
                ans= min(ans,level[u] + 1 + level[v]);
                // prune_level = level[v] - 1;
                // int cycle_len = level[u] + 1 + level[v];
                // if(cycle_len<min_cycle){
                //     min_cycle = cycle_len;
                //     best_u = u;
                //     best_v = v;
                // }
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    vector<long long> nums(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &nums[i]);
		if (nums[i] == 0) {
			i--;
			n--;
			continue;
		}
		for (int k = 0; k < K; k++)
			if ((nums[i] >> k) & 1) {
				b[k]++;
				if (b[k] >= 3) {
					printf("3\n");
					return 0;
				}
			}
    }
    for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((nums[i] & nums[j]) != 0)
				graph[i].push_back(j);
        }
    for(int i = 0;i<n;i++)
        bfs(i);
    if(ans ==N )ans = -1;
    cout<<ans<<endl;
    return 0;
}