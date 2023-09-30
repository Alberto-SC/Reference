#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
/*
    Hopcroft-Karp
    bipartite matching in O(E√V) 
    TESTED in:
        [SPOJ-NITT4]
        [https://judge.yosupo.jp/problem/bipartitematching]
*/


struct Bipartite_Matching{
    vector<vector<int>> es;
    vector<int> d, match;
    vector<bool> used, used2;
    const int n, m;
    // n is size of L set and m is size of R set
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


signed main(){__
    int n,m,b,u,v;
    cin>>n>>m>>b;
    vector<vector<int>> grid(n,vector<int>(m,1));

    for(int i = 0;i<b;i++){
        cin>>u>>v;
        grid[u][v] =0;
    }

    vector<int> fx = {+1,-1,+0,+0};
    vector<int> fy = {+0,+0,+1,-1};
    auto isValid = [&](int x,int y){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    };
    auto getN = [&](int x,int y){
        return (x*m)+y;
    };
    Bipartite_Matching bm((n*m)/2,(n*m)/2);   
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==0)continue;
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(isValid(nx,ny)&&  grid[nx][ny]==1){
                    bm.add_edge(getN(i,j),getN(nx,ny));
                    bm.add_edge(getN(nx,ny),getN(i,j));
                }
            }
        }   
    }

    int mx = bm.bipartite_matching();
    int z= ((m*n)-b)-mx;
    if(mx == (n*m)-b)cout<<"Yes"<<endl;
    else cout<<"No"<<" "<<z<<endl;
};