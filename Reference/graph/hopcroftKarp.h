/**
 * Author: Chen Xing
 * Date: 2009-10-13
 * License: CC0
 * Source: N/A
 * Description: Fast bipartite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition, and $btoa$ should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex $i$ on the right side,
 * or $-1$ if it's not matched.
 * Usage: vi btoa(m, -1); hopcroftKarp(g, btoa);
 * Time: O(\sqrt{V}E)
 * Status: stress-tested by MinimumVertexCover, [SPOJ:MATCHING ,LightOJ-1356 , kattis:adkbipmatch ] 
 * 
 */
struct Bipartite_Matching{
    vector<vector<int>> es;
    vector<int> d, match;
    vector<bool> used, used2;
    const int n, m;
    Bipartite_Matching(int n, int m) : es(n), d(n), match(m), used(n), used2(n), n(n), m(m) {}

    void add_edge(int u, int v){
        es[u].push_back(v);
    }

    void bfs(){
        fill(begin(d), end(d), -1);
        queue<int> que;
        for(int i = 0; i < n; i++){
            if(!used[i]) que.emplace(i), d[i] = 0;
        }
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(auto &e: es[i]){
                int j = match[e];
                if(j != -1 && d[j] == -1){
                    que.emplace(j), d[j] = d[i]+1;
                }
            }
        }
    }

    bool dfs(int now){
        used2[now] = true;
        for(auto &e: es[now]){
            int u = match[e];
            if(u == -1 || (!used2[u] && d[u] == d[now]+1 && dfs(u))){
                match[e] = now, used[now] = true;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching(){
        fill(begin(match), end(match), -1), fill(begin(used), end(used), false);
        int ret = 0;
        while(true){
            bfs();
            fill(begin(used2), end(used2), false);
            int flow = 0;
            for(int i = 0; i < n; i++){
                if(!used[i] && dfs(i)) flow++;
            }
            if(flow == 0) break;
            ret += flow;
        }
        return ret;
    }
};

// If you graph is not dividen in proper way  (not divided in two sets L and R) call this function
int ConverLR(int n){
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
    Bipartite_matching BM(n-m,m,g);
    return BM.bipartite_matching();
}



