#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 2000007;
vector<int> g[maxn];
vector<int> gt[maxn];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT(int n) {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_edge(int u,int v,bool negU,bool negV){
    g[(u*2)+(negU?0:1)].push_back((v*2)+(negV?1:0));
    gt[(v*2)+(negV?1:0)].push_back((u*2)+(negU?0:1));
    g[(v*2)+(negV?0:1)].push_back((u*2)+(negU?1:0));
    gt[(u*2)+(negU?1:0)].push_back((v*2)+(negV?0:1));

}
signed main(){
	int t= 1,n,u,v,p,M,m,x,y,l,r;
    cin>>n>>p>>M>>m;
    int N = p+M;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        x--,y--;
        add_edge(x,y,0,0);
    }
    for(int i = 0;i<M-1;i++){
        add_edge(p+i,p+i+1,0,1);
    }
    for(int i = 0;i<p;i++){
        cin>>l>>r;
        add_edge(i,p+(l-1),1,0);
        if(r<M)
            add_edge(i,p+r,1,1);
    }

    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v,1,1);
    }
    // show_graph(2*N);
    if(!solve_2SAT(2*N))return cout<<-1<<endl,0;
    // for(int i = 0;i<N;i++)
        // cout<<assignment[i]<<" ";
    // cout<<endl;
    vector<int> ans;
    for(int i = 0;i<p;i++)
        if(assignment[i])ans.push_back(i+1);
    int i =0;
    for(;i<M;i++)
        if(!assignment[p+i])break;
    cout<<ans.size()<<" "<<i<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}  
