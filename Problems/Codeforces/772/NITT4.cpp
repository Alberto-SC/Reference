#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 10007;
vector<int> graph[maxn];

vector<int> Blossom(int n) {
    int timer = -1;
    vector<int> mate(n, -1), label(n), parent(n), orig(n), aux(n, -1), q;

    auto lca = [&](int x, int y) {
        for (timer++; ; swap(x, y)) {
            if (x == -1) continue;
            if (aux[x] == timer) return x;
            aux[x] = timer;
            x = (mate[x] == -1 ? -1 : orig[parent[mate[x]]]);
        }
    };
    auto blossom = [&](int v, int w, int a) {
        while (orig[v] != a) {
            parent[v] = w; w = mate[v];
            if (label[w] == 1) label[w] = 0, q.push_back(w);
            orig[v] = orig[w] = a; v = parent[w];
        }
    };
    auto augment = [&](int v) {
        while (v != -1) {
            int pv = parent[v], nv = mate[pv];
            mate[v] = pv; 
            mate[pv] = v;
            v = nv;
        }
    };
    auto bfs = [&](int root) {
        fill(label.begin(), label.end(), -1);
        iota(orig.begin(), orig.end(), 0);
        q.clear(); 
        label[root] = 0; q.push_back(root);
        for (int i = 0; i < (int)q.size(); ++i) {
            int v = q[i];
            for (auto x : graph[v]) {
                if (label[x] == -1) {
                    label[x] = 1;
                    parent[x] = v;
                    if (mate[x] == -1) 
                        return augment(x), 1;
                    label[mate[x]] = 0; q.push_back(mate[x]);
                } 
                else if (label[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v], orig[x]);
                    blossom(x, v, a); 
                    blossom(v, x, a);
                }
            }
        }
        return 0;
    };
    for (int i = 0; i < n; i++) 
        if (mate[i] == -1) 
            bfs(i);
    return mate;
}

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
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==0)continue;
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(isValid(nx,ny)&&  grid[nx][ny]==1){
                    graph[getN(i,j)].push_back(getN(nx,ny));
                    graph[getN(nx,ny)].push_back(getN(i,j));
                }
            }
        }   
    }

    vector<int> match= Blossom(n*m);
    int cont = 0,z= 0;
    for(int i = 0;i<n*m;i++){
        if(grid[i/m][i%m]==0)continue;
        if(match[i]!= -1)cont++;
        else z++;
    }
    if(cont == (n*m)-b)cout<<"Yes"<<endl;
    else cout<<"No"<<" "<<z<<endl;
};