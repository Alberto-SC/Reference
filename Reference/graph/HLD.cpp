/**
 * Author: Alberto Silva
 * Source: https://codeforces.com/blog/entry/53170
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most log(n)
 * light edges.
 * Time: O((\log N)^2) per query in a path
 * Status: stress-tested against old HLD
 */

// #include "SegmentTree.cpp"
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
void add_edge(int u,int v,int c){
    graph[u].push_back({v,c});
    graph[v].push_back({u,c});
}
vector<int> p(maxn),head(maxn),stpos(maxn),lvl(maxn),sz(maxn),val(maxn);
vector<int> heavy(maxn,-1);

int cn = 0;
void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sz[u]= 1;
    int mx= 0;
    p[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sz[v.x]>mx){
            mx = sz[v.x];
            heavy[u] = v.x;
        }
        sz[u]+=sz[v.x];
    }
}

void HLD(int u,int ch,int n){
    head[u] = ch;
    stpos[u] = cn++;
    for(int i=0, currpos = 0; i < n; ++i)
		if(p[i] == -1 || heavy[p[i]] != i)
			for(int j = i; j != -1; j = heavy[j])
			{
				head[j] = i;
				stpos[j] = currpos;
				currpos++;
            }
} 


int query(int a,int b,int n){
    int res = 0;
    while(head[a]!= head[b]){
        if(lvl[head[a]]< lvl[head[b]])
            swap(a,b);
        res += query(1,0,n-1,stpos[head[a]],stpos[a]);
        a = p[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    res+=query(1,0,n-1,stpos[a],stpos[b]);
    return res;
}

int update(int a,int b,int val, int n){ 
    while(head[a] != head[b]){
        if(lvl[head[a]] < lvl[head[b]])
            swap(a,b);
        update(1,0,n-1,stpos[head[a]],stpos[a],val);
        a = p[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    update(1,0,n-1,stpos[a],stpos[b],val);
}
