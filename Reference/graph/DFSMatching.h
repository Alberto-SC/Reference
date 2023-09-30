/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source:
 * Description: Simple bipartite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition, and $btoa$ should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex $i$ on the right side,
 * or $-1$ if it's not matched.
 * Time: O(VE)
 * Usage: vi btoa(m, -1); dfsMatching(g, btoa);
 * Status: works but better use hopcroftKarp
 */
#pragma once

bool find(int j, vector<vector<int>>& g, vector<int>& btoa, vector<int>& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vector<int>>& g, vector<int>& btoa) {
	vector<int> vis;
	for(int i = 0;i<g.size();i++) {
		vis.assign(btoa.size(), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return btoa.size() - (int)count(btoa.begin(),btoa.end(), -1);
}


const int maxn = 100007;
vector<int> graph[maxn];
// If you graph is not dividen in proper way  (not divided in two sets L and R) call this function
vector<int> ConverLR(int n){
    vector<bool> vis(n);
    vector<int> color(n);


    auto bfsColor = [&](int s){
        vector<int> q;
        q.push_back(s); 
        while(q.size()){
            int u = q.back();
            vis[u] = true;
            q.pop_back();
            for(auto v:graph[u]){
                if(!vis[v]){
                    q.push_back(v);
                    color[v] = color[u]^1; 
                }
            }
        }
    };

    for(int i = 0;i<n;i++)
        if(!vis[i])
            bfsColor(i);
    
    map<int,int> mpR;
    int m= 0,key = 0;
    vector<vector<int>> g;
    for(int i = 0;i<n;i++){
        if(color[i]){
            g.push_back(vector<int>());
            for(auto d:graph[i]){
                if(!mpR.count(d))
                    mpR[d] = key++;
                g.back().push_back(mpR[d]);
            }
        }
        else m++;
    }
	vector<int> match(m, -1);
    return dfsMatching(g,match);
}

