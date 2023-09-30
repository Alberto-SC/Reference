#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> deep(maxn);
vector<int> P(maxn);
vector<int> sz(maxn);
int parent[25][maxn];
void dfs(int u,int p = -1,int d = 0){
    deep[u] = d;
    parent[0][u] = p;
    P[u] =p;
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u,d+1);
        sz[u]+=sz[v];
    }
}

void build(int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<25;j++)
            parent[j][i] = -1;
    dfs(0);
    for(int i = 1;i<25;i++){
        for(int u = 0;u<n;u++){
            if(parent[i-1][u]!= -1)
                parent[i][u] = parent[i-1][parent[i-1][u]];
        }
    }
}

int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    for(int i = 24;i>=0;i--){
        if(diff & (1<<i))
            v = parent[i][v];
    }
    if(u == v)return u; 

    for(int i = 24;i>=0;i--){
        if(parent[i][u]!= parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

#define x first
#define y second
bool check(int m,int n){
    pair<int,int> mx1 = {-1,-1},mx2 = {-1,-1};
    vector<bool> b(n);
    for(int i = 0;i<=m;i++){
        if(deep[i]>mx1.x){
            mx1.x = deep[i];
            mx1.y = i;
        }
    }
    int u = mx1.y;
    while(u!=0){
        b[u] = true;
        u = P[u];
    }
    for(int i = 0;i<=m;i++){
        if(i== mx1.y|| b[i]==true)continue;
        if(deep[i]>mx2.x){
            mx2.x = deep[i];
            mx2.y = i;
        }
    }
    if(mx2.y==-1)mx2 ={0,0};
    int LCA = lca(mx1.y,mx2.y);
    if(LCA!=0)return false;
    u = mx2.y;
    while(u!=0){
        b[u] = true;
        u = P[u];
    }
    b[0] = true;
    int mex;
    for(int i = 0;i<n;i++)
        if(!b[i])return i>m; 
    return true;

}

signed main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)
            graph[i].clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        build(0);
        int l = 0,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,n))
                l = m;
            else 
                r = m;
        }

        pair<int,int> mx1 ={-1,-1},mx2 = {-1,-1};
        vector<bool> b(n);
        for(int i = 0;i<=l;i++){
            if(deep[i]>mx1.x){
                mx1.x = deep[i];
                mx1.y = i;
            }
        }
        u = mx1.y;
        while(u!=0){
            b[u] = true;
            u = P[u];
        }
        for(int i = 0;i<=l;i++){
            if(i== mx1.y|| b[i]==true)continue;
            if(deep[i]>mx2.x){
                mx2.x = deep[i];
                mx2.y = i;
            }
        }
        if(mx2.y==-1)mx2 ={0,0};
        u = mx2.y;
        while(u!=0){
            b[u] = true;
            u = P[u];
        }
        b[0] = true;

        vector<int> ans(n+1);
        u = mx1.y,v = mx2.y;
        while(v!= 0 || u!=0){
            if(u<v)
                swap(u,v);
            int who = u,x= 1,y= 1;
            u = P[u];
            b[who] = false;
            for(auto y:graph[u]){
                if(y== P[u]|| y == who|| b[y])continue;
                y+=sz[y];
            }
            for(auto y:graph[v]){
                if(y== P[u]|| y == who|| b[y])continue;
                x+=sz[y];
            }
            if( u ==v)x--;
            ans[who] = x*y;
        }
        for(auto z:graph[0]){
            ans[0] += (sz[z]*(sz[z]-1))/2;
        }
        if(l==n-1)
            ans[n] = 1;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
