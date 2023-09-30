#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

const int MAXN = 40010;
vector <int> adj[MAXN];
vector <bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];


void bfs(int n1, int n2){
    fill(dist, dist+n1, -1);
    queue<int> q;

    for(int u=0; u<n1; u++){
        if(!used[u]){
            q.push(u);
            dist[u] = 0;
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j=0; j<(int)adj[u].size(); j++){
            int v = match[adj[u][j]];
            if(v >= 0 && dist[v] < 0){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

bool dfs(int u){
    visit[u] = true;
    for(int j=0; j< (int)adj[u].size(); j++){
        int v = match[adj[u][j]];
        if(v<0 || (!visit[v] && (dist[v] == dist[u] + 1) && dfs(v))){
            match[adj[u][j]] = u;
            used[u] = true;
            return true;
        }
    }
    return false; 
}

int hopcroft_karp(int n1, int n2){
    fill(match, match+n2, -1);
    fill(used.begin(), used.end(), false);
    int res = 0;

    for(;;){
        bfs(n1,n2);
        fill(visit.begin(), visit.end(), false);
        int f=0;
        for(int u=0; u<n1; u++){
            if(!used[u] && dfs(u)){
                f++;
            }

        }
        if(f == 0){
            return res;
        }
        res += f;
    }
    return res;
}

int main(){
	map<string,int> h,m;
	int n; cin >> n;
	int idH=n;

	string girl, mens;
	for(int i = 0;i<n;i++){
		cin >> girl;
		int b; cin >> b;
		while(b--){
			cin >> mens;
			if(h.count(mens) == 0){
				h[mens]=idH++;
			}
			adj[i].push_back(h[mens]);
		}
	}

	int ans = hopcroft_karp(n, h.size());
	//cout << ans << endl;
	cout << n+h.size()-ans << endl;
	return 0;
}