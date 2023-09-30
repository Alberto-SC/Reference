#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
const int mxlog = 25;

vector<int> graph[maxn];
struct assasins{
    int u,leaf,days;
};

vector<assasins> leafs;
int parent[mxlog][maxn];
vector<int> deep(maxn);
vector<int> P(maxn);
int n;
void dfs(int u,int p = -1,int d = 0){
    deep[u] = d;
    parent[0][u] = p;
    P[u] = p;
    int cont = 0;
    for(auto v:graph[u]){
        if(v== p)continue;
        dfs(v,u,d+1);
        cont++;
    }
    if(!cont)leafs.push_back({u,u,0});
}

void build(){
    for(int i = 0;i<n;i++)
        if(deep[i]== -1)dfs(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<n;u++){
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
void init(){
    for(int i = 0;i<n;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
    for(int i = 0;i<n;i++)deep[i]= -1;
    dfs(0);
    build();
}
signed main(){
	int t= 1,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        leafs.clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        init();
        vector<bool> active(n+1);
        while(1){
            int N = leafs.size();
            bool flag = false;
            active.assign(n+1,0);
            for(int i = 0;i<N;i++){
                leafs[i].u = P[leafs[i].u];
                leafs[i].days++;
                if(leafs[i].u==0)flag = true;
                active[leafs[i].u] = true;
            }
            if(flag)break;
            
            vector<bool> q(n);
            vector<int> change(n,-1);
            for(int i = 0;i<N;i++){
                int v = P[leafs[i].u];
                while(v){
                    // cout<<"I: "<<leafs[i].u<<" "<<v<<endl;
                    if(active[v]){
                        change[i] = v;
                        q[v] = true;
                    }
                    v = P[v];
                }
            }
            vector<assasins> nw;
            for(int i = 0;i<N;i++){
                if(active[leafs[i].u] && !q[leafs[i].u]){
                    nw.push_back(leafs[i]);
                    if(change[i]!=-1){
                        nw.back().u = change[i];
                        nw.back().days++;
                    }
                }
            }
            leafs= nw;
        }
        sort(leafs.begin(),leafs.end(),[&](assasins a,assasins b){
            return a.leaf<b.leaf;
        });
        int ans = n+1;
        for(int i = 0;i<leafs.size();i++){
            if(leafs[i].u==0)
                ans = min(ans,leafs[i].days);
        }
    
        vector<int> res;
        for(int i = 0;i<leafs.size();i++){
            if(leafs[i].u==0 && leafs[i].days==ans)res.push_back(leafs[i].leaf+1);
        }
        cout<<res.size()<<" "<<ans<<endl;
        for(auto c:res)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  



