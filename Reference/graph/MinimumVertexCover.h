/**
 * Author: Alberto Silva
 * Date: 2016-12-15
 * License: CC0
 * Description: Finds a minimum vertex cover in a bipartite graph.
 *  The size is the same as the size of a maximum matching, and
 *  the complement is a maximum independent set.
 *  A vertex cover is a set of vertex such that every edge has an endpoint 
 * to one of the vertex in the set
 * Status: \[LightOJ-1356\] 
 */

// #include "hopcroftKarp.h"

vector<int> cover(vector<vector<int>>& g, int n, int m) {
	//From maximum matrching de minimun vertex cover is the nodes not matched for the left side 
    // and the nodes visited in the right part if we run a dfs from no matched nodes in the left j
    Bipartite_Matching BM(n,m,g);
    int res = BM.bipartite_matching();
    vector<int> match = BM.match;
	vector<bool> lfound(n, true), seen(m);
	for (int it : match) if (it != -1) lfound[it] = false;
	vector<int> q, cover;
	for(int i = 0;i<n;i++) if (lfound[i]) q.push_back(i);

	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	for(int i = 0;i<n;i++) if (!lfound[i]) cover.push_back(i);
	for(int i = 0;i<m;i++) if (seen[i]) cover.push_back(n+i);
	assert(cover.size() == res);
	return cover;
}
