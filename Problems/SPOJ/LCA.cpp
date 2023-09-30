#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
vector<int> graph[maxn];
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

struct LCA {
    vector<int> euler, first, st,height;
    LCA(int n, int root) {
        first.resize(n);
        height.resize(n);
        euler.reserve(n * 2);
        dfs(root);
        int m = euler.size();
        st.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(int u, int h = 0,int p = -1) {
        first[u] = euler.size();
        height[u] = h;
        euler.push_back(u);
        for (auto v : graph[u]) {
            if (v == p) continue;
            dfs(v, h + 1,u);
            euler.push_back(u);
        }
    }

    void build(int node ,int l,int r){
        if(l == r)st[node] = euler[l];
        else {
            int m = (l+r)>>1;
            build(node<<1,l,m);
            build(node<<1|1,m+1,r);
            int a = st[node<<1];
            int b = st[node<<1|1];
            st[node] = height[a]<height[b]?a:b;
        }
    }

    int query(int node,int sl,int sr,int l,int r){
        if(sl>r || sr<l|| sl>sr)return -1;
        else if(sl>=l && sr<=r)
            return st[node];

        int m = (sl+sr)>>1;
        int a = query(node<<1,sl,m,l,r);
        int b = query(node<<1|1,m+1,sr,l,r);
        if(a == -1)return b;
        if(b == -1)return a;
        return height[a]<height[b]?a:b;
    }

    int lca(int u, int v){
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

int main(){
    int t,n,u,m,q,v;
    cin>>t;
    int cont = 1;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i= 0;i<n;i++){
            cin>>m;
            for(int j = 0;j<m;j++){
                cin>>u;
                u--;
                graph[i].push_back(u);
            }
        }
        LCA lca(n,0);
        // print(lca.euler);
        cin>>q;
        cout<<"Case "<<cont<<":"<<endl;
        for(int i = 0;i<q;i++){
            cin>>u>>v;
            u--,v--;
            cout<<lca.lca(u,v)+1<<endl;
        }
        cont++;
    }
    return 0;
}