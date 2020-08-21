/* Needed: 
		stsz[u] := size of subtree of u
		p[u] := parent of u
	Complexity: O(nlogn)
	Status: tested
*/
const int MX = 100005;
vi adj[MX];
bitset<MX> cent;
int stsz[MX];

void dfs (int u, int p) {
    stsz[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);
            stsz[u] += sz[v];
        }
}

int descomp (int u) {
    int tam = 1;

    for (int v : adj[u])
        if (!cent[v]) // si cent[v] es false, entonces el nodo v todavía existe
            tam += stsz[v];

    while (1) {
        int ind = -1;

        for (int v : adj[u])
            if (!cent[v] && 2 * stsz[v] > tam)
                ind = v;

        if (ind == -1)
            break;

        stsz[u] = tam - stsz[ind];
        u = ind;
    }

    cent[u] = 1;

	//Operation here
    
	for (int v : adj[u])
        if (!cent[v])
            p[descomp(v)] = u;

    return u;
}


// main()
// dfs(1, -1)
// decomp(1)