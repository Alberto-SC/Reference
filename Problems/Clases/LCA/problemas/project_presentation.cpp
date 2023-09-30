#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
const int mxlog = 25;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> deep(maxn);
vector<int> ss(maxn);
vector<int> pos(maxn);
int parent[mxlog][maxn];
bool comp(int a,int b){
    return pos[a]<pos[b];
}

void dfs(int u,int &idx,int p = -1,int d =1){
    pos[u] = idx;
    deep[u] = d;
    parent[0][u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,++idx,u,d+1);
    }
}


void build(){
    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<maxn;u++){
            if(parent[i-1][u]!= -1)
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
    }
}

int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    for(int i = mxlog-1;i>=0;i--){
        if(diff & (1<<i))
            v = parent[i][v];
        
    }
    if(u == v)return u; 

    for(int i = mxlog-1;i>=0;i--){
        if(parent[i][u]!= parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}
void init(int root){
    for(int i = 0;i<maxn;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
    for(int i = 0;i<maxn;i++)deep[i]= -1;
    int idx = 0;
    dfs(root,idx);
    build();
}

int main(){__
    int n,m,p,root;
    cin>>n>>m;
    vector<int> pr(n);
    for(auto &c:pr)cin>>c;
    for(int i = 0;i<n;i++){
        cin>>p;
        p--;
        if(p == -1)root = i;
        if(p == -1)continue;
        add_edge(i,p);
    }
    vector<int> projects[m];
    init(root);
    for(int i = 0;i<n;i++)
        projects[pr[i]-1].push_back(i);
    for(int i = 0;i<m;i++)
        sort(projects[i].begin(),projects[i].end(),comp);

    vector<int> ans(m);
    for(int i = 0;i<m;i++){
        int total =deep[projects[i][0]];
        int last = projects[i][0];
        for(int j = 1 ;j<projects[i].size();j++){
            int lcaa = lca(last,projects[i][j]);
            total+=deep[projects[i][j]]-deep[lcaa];
            last = projects[i][j];
        }
        ans[i] = total;
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}